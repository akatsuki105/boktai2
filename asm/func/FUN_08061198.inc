	push {r4, r5, r6, lr}
	mov ip, r0
	movs r5, #0x99
	lsls r5, r5, #2
	add r5, ip
	movs r0, #0xd6
	lsls r0, r0, #2
	add r0, ip
	ldrb r1, [r0]
	cmp r1, #5
	bne _080611D4
	ldr r0, _080611CC @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r4, r0, #0
	adds r4, #0xa
	cmp r4, #0x63
	ble _080611C2
	movs r4, #0x63
_080611C2:
	ldr r0, _080611D0 @ =0x00000362
	add r0, ip
	ldrh r1, [r0]
	b _0806121C
	.align 2, 0
_080611CC: .4byte 0x030046A0
_080611D0: .4byte 0x00000362
_080611D4:
	ldr r0, _08061204 @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r2, #0
	ldrsh r4, [r0, r2]
	cmp r1, #0
	bne _0806120C
	ldr r0, _08061208 @ =0x00000362
	add r0, ip
	ldrh r0, [r0]
	ldrh r1, [r5, #0xe]
	adds r0, r0, r1
	movs r2, #0x16
	ldrsh r1, [r5, r2]
	adds r1, r0, r1
	movs r0, #0x9f
	lsls r0, r0, #2
	add r0, ip
	ldr r2, [r0]
	movs r0, #1
	orrs r2, r0
	movs r6, #2
	b _0806122A
	.align 2, 0
_08061204: .4byte 0x030046A0
_08061208: .4byte 0x00000362
_0806120C:
	ldr r0, _08061284 @ =0x00000362
	add r0, ip
	ldrh r0, [r0]
	ldrh r1, [r5, #0xe]
	adds r0, r0, r1
	movs r2, #0x16
	ldrsh r1, [r5, r2]
	subs r1, r0, r1
_0806121C:
	movs r0, #0x9f
	lsls r0, r0, #2
	add r0, ip
	ldr r2, [r0]
	movs r0, #2
	orrs r2, r0
	movs r6, #1
_0806122A:
	ldr r0, _08061288 @ =0x00000446
	add r0, ip
	ldrh r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _08061242
	ldr r0, _0806128C @ =0x00000442
	add r0, ip
	ldrh r0, [r0]
	cmp r0, #8
	bne _08061242
	movs r3, #1
_08061242:
	cmp r3, #0
	bne _08061252
	movs r0, #0x9f
	lsls r0, r0, #2
	add r0, ip
	ldr r0, [r0]
	cmp r0, #0x40
	bne _08061254
_08061252:
	movs r2, #0x40
_08061254:
	cmp r1, #0x63
	ble _0806125A
	movs r1, #0x63
_0806125A:
	adds r0, r1, r4
	asrs r0, r0, #1
	ldrh r5, [r5, #2]
	adds r1, r0, r5
	movs r0, #0xd6
	lsls r0, r0, #2
	add r0, ip
	ldrb r0, [r0]
	cmp r0, #5
	bne _08061272
	ldr r0, _08061290 @ =0x03002B74
	strh r1, [r0]
_08061272:
	movs r0, #0xb6
	lsls r0, r0, #1
	add r0, ip
	adds r3, r6, #0
	bl FUN_08236514
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08061284: .4byte 0x00000362
_08061288: .4byte 0x00000446
_0806128C: .4byte 0x00000442
_08061290: .4byte 0x03002B74
