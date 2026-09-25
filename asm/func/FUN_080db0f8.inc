	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, _080DB174 @ =0x03002BE0
	mov sb, r0
	ldr r5, [r0]
	cmp r5, #0
	bne _080DB110
	b _080DB24C
_080DB110:
	add r2, sp, #4
	adds r3, r6, #0
	adds r3, #0x9c
	adds r4, r5, #0
	adds r4, #0x2c
	ldrh r1, [r5, #0x2c]
	ldrh r0, [r3]
	subs r1, r1, r0
	mov ip, r1
	mov r1, ip
	strh r1, [r2]
	ldrh r0, [r4, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r1, [r4, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r2, #4]
	movs r4, #2
	ldrsh r0, [r2, r4]
	adds r7, r2, #0
	mov r8, r3
	cmp r0, #0
	bge _080DB144
	rsbs r0, r0, #0
_080DB144:
	cmp r0, #0x1f
	bgt _080DB1CA
	mov r0, ip
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe0
	bhi _080DB1CA
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0xa0
	bgt _080DB1CA
	movs r0, #0x3a
	rsbs r0, r0, #0
	cmp r1, r0
	blt _080DB1CA
	ldr r0, _080DB178 @ =0x000003FF
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _080DB17C
	movs r0, #0
	b _080DB1C6
	.align 2, 0
_080DB174: .4byte 0x03002BE0
_080DB178: .4byte 0x000003FF
_080DB17C:
	adds r0, r6, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	strb r0, [r4]
	adds r2, r6, #0
	adds r2, #0x40
	ldrh r0, [r2]
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r2]
	adds r2, #0x12
	ldrh r0, [r2]
	movs r1, #4
	orrs r0, r1
	strh r0, [r2]
	mov r2, sb
	ldr r0, [r2]
	movs r4, #0x80
	lsls r4, r4, #3
	adds r0, r0, r4
	ldrb r1, [r0]
	adds r0, r6, #0
	adds r0, #0x48
	strh r1, [r0]
	movs r1, #6
	mov r0, sp
	strh r1, [r0]
	movs r0, #2
	movs r1, #1
	mov r2, sp
	bl FUN_080ec7e8
	ldr r0, _080DB25C @ =0x00000115
	bl PlaySound_082406e0
	movs r0, #1
_080DB1C6:
	cmp r0, #0
	bne _080DB24C
_080DB1CA:
	adds r0, r7, #0
	bl FUN_08086a28
	cmp r0, #0
	beq _080DB24C
	bl FUN_08086850
	cmp r0, #0
	beq _080DB24C
	ldrh r0, [r7]
	mov r2, r8
	ldrh r1, [r2]
	subs r0, r0, r1
	add r1, sp, #4
	strh r0, [r1]
	ldrh r0, [r7, #2]
	ldrh r1, [r2, #2]
	subs r0, r0, r1
	strh r0, [r7, #2]
	ldrh r1, [r7, #4]
	ldrh r0, [r2, #4]
	subs r1, r1, r0
	strh r1, [r7, #4]
	movs r4, #2
	ldrsh r0, [r7, r4]
	cmp r0, #0
	bge _080DB202
	rsbs r0, r0, #0
_080DB202:
	cmp r0, #0x1f
	bgt _080DB24C
	ldrh r0, [r7]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe0
	bhi _080DB24C
	lsls r0, r1, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0xa0
	bgt _080DB24C
	movs r0, #0x3a
	rsbs r0, r0, #0
	cmp r1, r0
	blt _080DB24C
	bl FUN_08086878
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, r1
	bge _080DB24C
	adds r0, r6, #0
	adds r0, #0x42
	movs r1, #0
	ldrsh r0, [r0, r1]
	bl FUN_0808689c
	adds r2, r6, #0
	adds r2, #0x40
	ldrh r0, [r2]
	movs r1, #0x40
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _080DB25C @ =0x00000115
	bl PlaySound_082406e0
_080DB24C:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DB25C: .4byte 0x00000115
