	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r1, _080CE084 @ =0x00000446
	adds r0, r4, r1
	ldrh r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _080CE022
	b _080CE1C4
_080CE022:
	ldr r2, _080CE088 @ =0x00000442
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _080CE094
	ldr r3, _080CE08C @ =0x0000097A
	adds r5, r4, r3
	ldrh r0, [r5]
	cmp r0, #0x3f
	bhi _080CE052
	cmp r0, #0
	bne _080CE04C
	ldr r0, [r4, #0x18]
	movs r1, #0xf7
	lsls r1, r1, #1
	bl Sound_PlayForPlayer
	ldr r0, _080CE090 @ =0x000003F1
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080CE04C:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_080CE052:
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080CE08C @ =0x0000097A
	adds r0, r4, r1
	ldrh r0, [r0]
	lsrs r0, r0, #1
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0xb
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	adds r5, r2, #0
	b _080CE0FE
	.align 2, 0
_080CE084: .4byte 0x00000446
_080CE088: .4byte 0x00000442
_080CE08C: .4byte 0x0000097A
_080CE090: .4byte 0x000003F1
_080CE094:
	ldr r2, _080CE0D8 @ =0x0000097A
	adds r6, r4, r2
	ldrh r0, [r6]
	adds r5, r4, #0
	adds r5, #0x90
	cmp r0, #0
	beq _080CE0FE
	ldr r3, _080CE0DC @ =0x000003F1
	adds r7, r4, r3
	ldrb r0, [r7]
	cmp r0, #0
	beq _080CE0B8
	ldr r0, [r4, #0x18]
	ldr r1, _080CE0E0 @ =0x00000336
	bl Sound_PlayForPlayer
	movs r0, #0
	strb r0, [r7]
_080CE0B8:
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CE0E4
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0xbc
	movs r1, #0x40
	b _080CE0F8
	.align 2, 0
_080CE0D8: .4byte 0x0000097A
_080CE0DC: .4byte 0x000003F1
_080CE0E0: .4byte 0x00000336
_080CE0E4:
	ldr r0, [r5]
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	ldrh r0, [r6]
	lsrs r0, r0, #1
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
_080CE0F8:
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_080CE0FE:
	ldr r1, _080CE118 @ =0x00000442
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #6
	bne _080CE192
	ldr r0, _080CE11C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CE120
	movs r2, #1
	rsbs r2, r2, #0
	b _080CE124
	.align 2, 0
_080CE118: .4byte 0x00000442
_080CE11C: .4byte 0x03002C68
_080CE120:
	movs r3, #0x18
	ldrsh r2, [r0, r3]
_080CE124:
	ldr r0, [r4, #0x18]
	cmp r0, r2
	bne _080CE136
	adds r1, r4, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	b _080CE17C
_080CE136:
	ldr r1, _080CE168 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r2, _080CE16C @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _080CE156
	ldr r3, _080CE170 @ =0x00000442
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #4
	bne _080CE156
	movs r2, #1
_080CE156:
	cmp r2, #0
	beq _080CE174
	adds r1, r4, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	b _080CE17C
	.align 2, 0
_080CE168: .4byte 0x03002BE0
_080CE16C: .4byte 0x00000446
_080CE170: .4byte 0x00000442
_080CE174:
	adds r1, r4, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #1
_080CE17C:
	orrs r0, r2
	str r0, [r1]
	ldr r0, [r5]
	orrs r0, r2
	str r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	b _080CE1A4
_080CE192:
	adds r1, r4, #0
	adds r1, #0xe8
	ldr r0, [r1]
	ldr r2, _080CE1BC @ =0xFFFFFDFF
	ands r0, r2
	str r0, [r1]
	ldr r0, [r5]
	ands r0, r2
	str r0, [r5]
_080CE1A4:
	ldr r0, [r4, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080CE256
	ldr r0, _080CE1C0 @ =0x00000446
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _080CE256
	.align 2, 0
_080CE1BC: .4byte 0xFFFFFDFF
_080CE1C0: .4byte 0x00000446
_080CE1C4:
	ldr r1, _080CE208 @ =0x0000097A
	adds r6, r4, r1
	ldrh r0, [r6]
	adds r5, r4, #0
	adds r5, #0x90
	cmp r0, #0
	beq _080CE22E
	ldr r2, _080CE20C @ =0x000003F1
	adds r7, r4, r2
	ldrb r0, [r7]
	cmp r0, #0
	beq _080CE1E8
	ldr r0, [r4, #0x18]
	ldr r1, _080CE210 @ =0x00000336
	bl Sound_PlayForPlayer
	mov r3, r8
	strb r3, [r7]
_080CE1E8:
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CE214
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0xbc
	movs r1, #0x40
	b _080CE228
	.align 2, 0
_080CE208: .4byte 0x0000097A
_080CE20C: .4byte 0x000003F1
_080CE210: .4byte 0x00000336
_080CE214:
	ldr r0, [r5]
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	ldrh r0, [r6]
	lsrs r0, r0, #1
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
_080CE228:
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_080CE22E:
	ldr r1, [r5]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _080CE242
	ldr r0, _080CE260 @ =0xFFFFFDFF
	ands r1, r0
	str r1, [r5]
_080CE242:
	adds r1, r4, #0
	adds r1, #0xe8
	ldr r3, [r1]
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	beq _080CE256
	ldr r0, _080CE260 @ =0xFFFFFDFF
	ands r3, r0
	str r3, [r1]
_080CE256:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CE260: .4byte 0xFFFFFDFF
