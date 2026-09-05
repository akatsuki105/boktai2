	push {r4, r5, r6, r7, lr}
	bl FUN_080ef840
	cmp r0, #0
	beq _080EDA70
	ldr r0, _080EDA78 @ =0x03002C60
	ldr r5, [r0]
	ldr r4, [r5, #4]
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	cmp r4, #0
	beq _080EDA70
	movs r7, #0x80
	lsls r7, r7, #7
_080EDA46:
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080EDA68
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	ands r0, r7
	cmp r0, #0
	beq _080EDA68
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080ecbe8
_080EDA68:
	ldr r5, [r5]
	ldr r4, [r5, #4]
	cmp r4, #0
	bne _080EDA46
_080EDA70:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080EDA78: .4byte 0x03002C60
