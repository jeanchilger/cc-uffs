<?php

$totalQuestions = 12;
$rightQuestions = 0;

// Question 1
if (isset($_POST["q1"])) {
    $q1 = strtolower($_POST["q1"]);
    if ($q1 == "html") {
        $rightQuestions++;
        echo "<p>Questão 1: correta.</p>";

    } else {
        echo "<p>Questão 1: incorreta.</p>";
    }
}

// Question 2
if (isset($_POST["q2"])) {
    $q2 = strtolower($_POST["q2"]);
    if ($q2 == "css") {
        $rightQuestions++;
        echo "<p>Questão 2: correta.</p>";

    } else {
        echo "<p>Questão 2: incorreta.</p>";
    }
}

// Question 3
if (isset($_POST["q3"])) {
    $q3TotalRight = 3;
    $q3RightAlternatives = array("b", "d", "e");
    $q3Right = 0;
    foreach ($_POST["q3"] as $q3) {
        $q3 = strtolower($q3);
        for ($i=0; $i < 3; $i++) {
            if ($q3 == $q3RightAlternatives[$i]) {
                $q3Right++;
            }
        }
    }

    echo "<p>Questão 3: $q3Right corretas dentro de $q3TotalRight.</p>";

}

// Question 4
if (isset($_POST["q4"])) {
    $q4 = strtolower($_POST["q4"]);
    if ($q4 == "a") {
        echo "<p>Questão 4: correta.</p>";

    } else {
        echo "<p>Questão 4: incorreta.</p>";
    }
}

// Question 5
if (isset($_POST["q5"])) {
    $q5TotalRight = 4;
    $q5RightAlternatives = array("a", "d", "e", "f");
    $q5Right = 0;
    foreach ($_POST["q5"] as $q5) {
        $q5 = strtolower($q5);
        for ($i=0; $i < 4; $i++) {
            if ($q5 == $q5RightAlternatives[$i]) {
                $q5Right++;
            }
        }
    }

    echo "<p>Questão 5: $q5Right corretas dentro de $q5TotalRight.</p>";
}

// Question 6
if (isset($_POST["q6"])) {
    $q6 = strtolower($_POST["q6"]);
    if ($q6 == "a") {
        echo "<p>Questão 6: correta.</p>";

    } else {
        echo "<p>Questão 6: incorreta.</p>";
    }
}

// Question 7
if (isset($_POST["q7"])) {
    $q7 = strtolower($_POST["q7"]);
    $q8 = strtolower($_POST["q8"]);

    if ($q7 == "navegador web" && $q8 == "netscape navigator") {
        echo "<p>Questão 7: correta.</p>";

    } else {
        echo "<p>Questão 7: incorreta.</p>";
    }
}

$percentage = number_format($rightQuestions * 100 / $totalQuestions, 2, ".", "");

echo "Total de acertos: $rightQuestions (" . $percentage . ")%";

echo "<hr>";

// Comment
echo "<p>Seu comentário: </p>";
echo nl2br($_POST["comentario"]);

// Agreement
if (isset($_POST["concordo"])) {
    echo "<p>Você autorizou ";

} else {
    echo "<p>Você não autorizou ";
}

echo "o recebimento de propagandas no endereço " . $_POST["email"] . "</p>";

?>
