	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_0803cb24
	movs r0, #3
_0804FEBA:
	subs r0, #1
	cmp r0, #0
	bge _0804FEBA
	adds r4, r5, #0
	adds r4, #0x38
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804FED2
	bl FUN_0803cb4c
	movs r0, #0
	strb r0, [r4]
_0804FED2:
	adds r4, r5, #0
	adds r4, #0x39
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804FEE4
	bl FUN_0803cb6c
	movs r0, #0
	strb r0, [r4]
_0804FEE4:
	adds r4, r5, #0
	adds r4, #0x3a
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804FEF6
	bl FUN_0803cbb4
	movs r0, #0
	strb r0, [r4]
_0804FEF6:
	adds r4, r5, #0
	adds r4, #0x3b
	ldrb r0, [r4]
	cmp r0, #0
	beq _0804FF08
	bl FUN_0803cc54
	movs r0, #0
	strb r0, [r4]
_0804FF08:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
