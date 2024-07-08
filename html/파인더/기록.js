const text1 = localStorage.getItem('text1');
        const text2 = localStorage.getItem('text2');

        if (text1 && text2) {
            const regex = new RegExp(`(${text2})`, 'gi');
            const highlightedText = text1.replace(regex, '<span class="highlight">$1</span>');
            document.getElementById('outputtext').innerHTML = highlightedText;
            let history = JSON.parse(localStorage.getItem('history')) || [];
            history.push({text1, text2});
            localStorage.setItem('history', JSON.stringify(history));
            let historyText = history.map(entry => {
                const highlightedHistory = entry.text1.replace(new RegExp(`(${entry.text2})`, 'gi'), '<span class="highlight">$1</span>');
                return `<div>${highlightedHistory}</div>`;
            }).join("<br>");

            document.getElementById('outputtext').innerHTML += "<p><h3>History</p>" + historyText;
        } else {
            document.getElementById('outputtext').innerText = "텍스트를 찾을 수 없습니다.";
        }
        function clearHistory() {
            localStorage.clear();
            location.reload();
        }