	push {lr}
	adds r2, r0, #0
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0807A854
	movs r0, #0
	bl FUN_0807a7f8
	b _0807A898
_0807A854:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0807A864
	movs r0, #1
	bl FUN_0807a7f8
	b _0807A898
_0807A864:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0807A874
	movs r0, #2
	bl FUN_0807a7f8
	b _0807A898
_0807A874:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0807A884
	movs r0, #3
	bl FUN_0807a7f8
	b _0807A892
_0807A884:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0807A892
	movs r0, #4
	bl FUN_0807a7f8
_0807A892:
	movs r0, #0
	cmp r0, #0
	beq _0807A8A4
_0807A898:
	ldr r0, _0807A8A8 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0807A8A4
	bl FUN_08064058
_0807A8A4:
	pop {r0}
	bx r0
	.align 2, 0
_0807A8A8: .4byte 0x03002BE0
