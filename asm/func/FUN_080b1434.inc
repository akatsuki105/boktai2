	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _080B147C @ =0x03002C00
	ldr r0, [r0]
	ldr r1, _080B1480 @ =0x000001F5
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xb
	beq _080B1474
	adds r0, r4, #0
	bl FUN_080b1078
	cmp r0, #0
	beq _080B1474
	ldr r0, _080B1484 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	str r1, [sp]
	movs r3, #0
	bl FUN_0807bb3c
	ldr r5, _080B1488 @ =0x00000C16
	adds r1, r4, r5
	movs r0, #1
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ad1ec
_080B1474:
	movs r2, #0
	ldrb r3, [r4, #0x1e]
	b _080B148E
	.align 2, 0
_080B147C: .4byte 0x03002C00
_080B1480: .4byte 0x000001F5
_080B1484: .4byte 0x03002BE0
_080B1488: .4byte 0x00000C16
_080B148C:
	adds r2, #1
_080B148E:
	cmp r2, r3
	bge _080B14AC
	lsls r1, r2, #2
	ldr r5, _080B14B4 @ =0x00000BE8
	adds r0, r4, r5
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #4
	bne _080B148C
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080ad1ec
_080B14AC:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B14B4: .4byte 0x00000BE8
