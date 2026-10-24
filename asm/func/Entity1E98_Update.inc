	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	bl FUN_080a48bc
	movs r0, #0
	mov r8, r0
	ldrb r0, [r6, #0x18]
	cmp r8, r0
	bge _080A4A34
	adds r5, r6, #0
	adds r5, #0x68
	movs r0, #0x98
	lsls r0, r0, #1
	adds r4, r6, r0
	adds r7, r6, #0
	adds r7, #0x3c
_080A49F4:
	ldr r1, [r4, #0x14]
	adds r0, r7, #0
	bl _call_via_r1
	ldrb r0, [r4]
	cmp r0, #0
	beq _080A4A20
	subs r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _080A4A18
	movs r0, #0x60
	strh r0, [r5, #6]
	adds r0, r6, #0
	adds r0, #0x1c
	str r0, [r5, #0xc]
	b _080A4A20
_080A4A18:
	adds r0, r5, #0
	movs r1, #0x5f
	bl Video_SetAuxSpritePltt
_080A4A20:
	movs r0, #0x88
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r7, r7, r0
	movs r0, #1
	add r8, r0
	ldrb r0, [r6, #0x18]
	cmp r8, r0
	blt _080A49F4
_080A4A34:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
