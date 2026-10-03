	push {r4, r5, lr}
	adds r5, r0, #0
	adds r5, #0x3c
	adds r4, r0, #0
	adds r4, #0x48
	ldrb r0, [r5, #7]
	cmp r0, #0
	bne _0804FAB0
	ldrb r0, [r4, #7]
	cmp r0, #1
	beq _0804FAFA
	cmp r0, #2
	beq _0804FACC
	b _0804FAF6
_0804FAB0:
	cmp r0, #1
	bne _0804FAD8
	ldrb r0, [r4, #7]
	cmp r0, #1
	bne _0804FAC8
	ldr r1, [r5, #8]
	ldr r0, [r4, #8]
	cmp r1, r0
	blo _0804FAD4
	cmp r1, r0
	bhi _0804FAFA
	b _0804FAF6
_0804FAC8:
	cmp r0, #2
	bne _0804FAD4
_0804FACC:
	movs r0, #1
	movs r1, #1
	bl FUN_08050e50
_0804FAD4:
	movs r0, #0
	b _0804FAFC
_0804FAD8:
	ldrb r0, [r4, #7]
	cmp r0, #1
	beq _0804FAFA
	cmp r0, #2
	bne _0804FAFA
	movs r0, #1
	movs r1, #1
	bl FUN_08050e50
	ldr r1, [r5, #8]
	ldr r0, [r4, #8]
	cmp r1, r0
	blo _0804FAFA
	cmp r1, r0
	bhi _0804FAD4
_0804FAF6:
	movs r0, #2
	b _0804FAFC
_0804FAFA:
	movs r0, #1
_0804FAFC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
