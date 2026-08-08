	push {lr}
	bl FUN_0823e1b0
	cmp r0, #5
	bhi _082124E4
	lsls r0, r0, #2
	ldr r1, _082124C0 @ =_082124C4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_082124C0: .4byte _082124C4
_082124C4: @ jump table
	.4byte _082124E0 @ case 0
	.4byte _082124DC @ case 1
	.4byte _082124DC @ case 2
	.4byte _082124DC @ case 3
	.4byte _082124E0 @ case 4
	.4byte _082124E0 @ case 5
_082124DC:
	movs r0, #0
	b _082124E8
_082124E0:
	movs r0, #1
	b _082124E8
_082124E4:
	movs r0, #1
	rsbs r0, r0, #0
_082124E8:
	pop {r1}
	bx r1
