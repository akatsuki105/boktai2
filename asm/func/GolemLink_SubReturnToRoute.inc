	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x68
	adds r7, r0, #0
	ldr r0, _081C004C @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081BFF40
	movs r0, #0
	strb r0, [r1]
_081BFF40:
	adds r0, r7, #0
	bl GolemLink_TryChaseHitTarget
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _081BFF52
	bl _081C07CE
_081BFF52:
	ldr r1, _081C0050 @ =0x0000046B
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081BFF60
	bl _081C07C4
_081BFF60:
	movs r0, #3
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #8]
	strb r0, [r2]
	ldr r4, _081C0054 @ =0x00000469
	adds r4, r7, r4
	str r4, [sp, #0xc]
	strb r1, [r4]
	ldr r5, _081C0058 @ =0x0000046A
	adds r5, r7, r5
	str r5, [sp, #0x10]
	strb r3, [r5]
	ldr r6, _081C005C @ =0x00000484
	adds r6, r7, r6
	str r6, [sp, #0x14]
	str r3, [r6]
	ldr r0, _081C004C @ =0x0000046C
	adds r0, r0, r7
	mov sb, r0
	strb r1, [r0]
	ldr r2, _081C0060 @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r4, _081C0064 @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x18]
	strb r1, [r4]
	ldr r5, _081C0050 @ =0x0000046B
	adds r5, r5, r7
	mov sl, r5
	strb r3, [r5]
	ldr r6, _081C0068 @ =0x00000553
	adds r6, r6, r7
	mov r8, r6
	strb r0, [r6]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r6, r7, r0
	str r2, [r6]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r5, r7, r1
	strh r3, [r5]
	ldr r2, _081C006C @ =0x000004A4
	adds r0, r7, r2
	ldr r0, [r0]
	adds r4, r7, #0
	adds r4, #8
	adds r1, r4, #0
	bl Map_InitNavAgent
	movs r0, #0x80
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrh r2, [r1]
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov r0, sb
	str r0, [sp, #0x3c]
	ldr r0, [sp, #8]
	str r0, [sp, #0x2c]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x30]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x34]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x48]
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x40]
	mov r0, sl
	str r0, [sp, #0x38]
	mov r0, r8
	str r0, [sp, #0x60]
	str r6, [sp, #0x64]
	str r5, [sp, #0x20]
	str r4, [sp, #0x24]
	mov sl, r1
	cmp r3, #0
	bne _081C0008
	b _081C0600
_081C0008:
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	ldr r6, _081C0070 @ =0x00000554
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _081C0074 @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #6
	adds r0, r7, r5
	strb r4, [r0]
	ldr r0, _081C0078 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C007C
	movs r0, #1
	b _081C007E
	.align 2, 0
_081C004C: .4byte 0x0000046C
_081C0050: .4byte 0x0000046B
_081C0054: .4byte 0x00000469
_081C0058: .4byte 0x0000046A
_081C005C: .4byte 0x00000484
_081C0060: .4byte Enemy_WaitPendingState
_081C0064: .4byte 0x0000046D
_081C0068: .4byte 0x00000553
_081C006C: .4byte 0x000004A4
_081C0070: .4byte 0x00000554
_081C0074: .4byte 0x00000551
_081C0078: .4byte 0x030047A4
_081C007C:
	movs r0, #0
_081C007E:
	cmp r0, #0
	beq _081C0092
	adds r0, r7, #0
	bl Enemy_TargetNearestLinkPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C0090
	b _081C07CE
_081C0090:
	b _081C00A0
_081C0092:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _081C00E0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
_081C00A0:
	movs r0, #0x95
	lsls r0, r0, #3
	adds r3, r7, r0
	ldr r5, [r3]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r4, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _081C00DC
	cmp r1, #0
	blt _081C00DC
	ldr r0, _081C00E4 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081C00DC
	ldr r0, _081C00E8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C00EC
_081C00DC:
	movs r4, #0
	b _081C00FA
	.align 2, 0
_081C00E0: .4byte 0x03002BE0
_081C00E4: .4byte 0x030046A8
_081C00E8: .4byte 0x030046AC
_081C00EC:
	ldr r0, _081C010C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081C00FA:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C0110
	adds r0, #4
	b _081C011C
	.align 2, 0
_081C010C: .4byte 0x030046A4
_081C0110:
	ldr r0, _081C0130 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C011C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C0134
	cmp r2, #2
	beq _081C0138
	b _081C013C
	.align 2, 0
_081C0130: .4byte 0x030046A4
_081C0134:
	ldrb r0, [r5, #4]
	b _081C013A
_081C0138:
	ldrb r0, [r5]
_081C013A:
	subs r1, r1, r0
_081C013C:
	strh r1, [r5, #2]
	ldr r0, _081C0150 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C0154
	movs r0, #1
	b _081C0156
	.align 2, 0
_081C0150: .4byte 0x030047A4
_081C0154:
	movs r0, #0
_081C0156:
	cmp r0, #0
	beq _081C0194
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081C0176
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081C0172
	adds r2, r0, #0
_081C0172:
	cmp r2, #0
	bge _081C0180
_081C0176:
	ldr r2, _081C017C @ =0x000005C4
	adds r0, r7, r2
	b _081C05D4
	.align 2, 0
_081C017C: .4byte 0x000005C4
_081C0180:
	ldr r1, _081C0190 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081C01DC
	.align 2, 0
_081C0190: .4byte 0x03002BE0
_081C0194:
	movs r3, #0xec
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	ldrh r0, [r1, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C01C0
	cmp r1, #0
	blt _081C01C0
	ldr r0, _081C01C4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C01C0
	ldr r0, _081C01C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C01CC
_081C01C0:
	movs r5, #0
	b _081C01DA
	.align 2, 0
_081C01C4: .4byte 0x030046A8
_081C01C8: .4byte 0x030046AC
_081C01CC:
	ldr r0, _081C0214 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081C01DA:
	movs r2, #0
_081C01DC:
	ldr r4, _081C0218 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081C01FC
	ldr r1, _081C021C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081C01FC
	b _081C0518
_081C01FC:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081C0220
	movs r0, #0
	b _081C05EA
	.align 2, 0
_081C0214: .4byte 0x030046A4
_081C0218: .4byte 0x00000256
_081C021C: .4byte 0x03002BE0
_081C0220:
	ldr r0, _081C027C @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	mov r3, sl
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _081C0280
	movs r6, #0xb7
	lsls r6, r6, #3
	adds r0, r7, r6
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x40]
	strb r2, [r3]
	ldr r6, [sp, #0x38]
	strb r5, [r6]
	ldr r3, [sp, #0x60]
	strb r0, [r3]
	ldr r6, [sp, #0x64]
	str r1, [r6]
	ldr r0, [sp, #0x20]
	strh r4, [r0]
	movs r0, #0xc
	ldr r1, [sp, #0x2c]
	strb r5, [r1]
	ldr r3, [sp, #0x30]
	strb r5, [r3]
	ldr r5, [sp, #0x34]
	strb r0, [r5]
	ldr r6, [sp, #0x48]
	str r4, [r6]
	ldr r0, [sp, #0x3c]
	strb r2, [r0]
	b _081C03CE
	.align 2, 0
_081C027C: .4byte 0x00000222
_081C0280:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x40]
	strb r0, [r2]
	ldr r4, [sp, #0x38]
	strb r5, [r4]
	ldr r2, [sp, #0x60]
	strb r0, [r2]
	ldr r4, [sp, #0x64]
	str r1, [r4]
	ldr r1, [sp, #0x20]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x2c]
	strb r5, [r2]
	ldr r4, [sp, #0x30]
	strb r5, [r4]
	ldr r5, [sp, #0x34]
	strb r1, [r5]
	ldr r1, [sp, #0x48]
	str r3, [r1]
	ldr r2, [sp, #0x3c]
	strb r0, [r2]
	ldr r5, [r6]
	mov r3, r8
	ldr r0, [r3, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r3, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C02E4
	cmp r1, #0
	blt _081C02E4
	ldr r0, _081C02E8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C02E4
	ldr r0, _081C02EC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C02F0
_081C02E4:
	movs r4, #0
	b _081C02FE
	.align 2, 0
_081C02E8: .4byte 0x030046A8
_081C02EC: .4byte 0x030046AC
_081C02F0:
	ldr r0, _081C0310 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C02FE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C0314
	adds r0, #4
	b _081C0320
	.align 2, 0
_081C0310: .4byte 0x030046A4
_081C0314:
	ldr r0, _081C0334 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C0320:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C0338
	cmp r2, #2
	beq _081C033C
	b _081C0340
	.align 2, 0
_081C0334: .4byte 0x030046A4
_081C0338:
	ldrb r0, [r5, #4]
	b _081C033E
_081C033C:
	ldrb r0, [r5]
_081C033E:
	subs r1, r1, r0
_081C0340:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C0368
	cmp r1, #0
	blt _081C0368
	ldr r0, _081C036C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C0368
	ldr r0, _081C0370 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C0374
_081C0368:
	movs r4, #0
	b _081C0382
	.align 2, 0
_081C036C: .4byte 0x030046A8
_081C0370: .4byte 0x030046AC
_081C0374:
	ldr r0, _081C0394 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C0382:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C0398
	adds r0, #4
	b _081C03A4
	.align 2, 0
_081C0394: .4byte 0x030046A4
_081C0398:
	ldr r0, _081C03B8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C03A4:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081C03BC
	cmp r3, #2
	beq _081C03C0
	b _081C03C4
	.align 2, 0
_081C03B8: .4byte 0x030046A4
_081C03BC:
	ldrb r0, [r5, #4]
	b _081C03C2
_081C03C0:
	ldrb r0, [r5]
_081C03C2:
	subs r2, r2, r0
_081C03C4:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081C03CE:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	ldr r6, _081C03F8 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x44]
	cmp r0, #0
	bne _081C04DC
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081C03FC
	movs r0, #1
	b _081C03FE
	.align 2, 0
_081C03F8: .4byte 0x00000482
_081C03FC:
	movs r0, #0
_081C03FE:
	ldr r3, _081C04EC @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x44]
	cmp r0, #0
	bne _081C04DC
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r6, _081C04F0 @ =0x0000054F
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _081C04F4 @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x54]
	ldr r1, _081C04F8 @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x58]
	ldr r2, _081C04FC @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	ldr r4, _081C0500 @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	ldr r5, _081C0504 @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x28]
	ldr r6, _081C0508 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x50]
	ldr r6, _081C050C @ =0x0203B400
	ldr r1, _081C0510 @ =0x030046B8
	ldr r5, _081C0514 @ =0x000003FF
	movs r2, #3
	mov r4, r8
_081C044E:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r5
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r2
	lsls r0, r0, #6
	cmp r0, r4
	bne _081C046C
	adds r3, #1
	cmp r3, #3
	ble _081C044E
	mov r0, r8
_081C046C:
	movs r3, #0
	mov r1, sb
	strb r0, [r1]
	ldr r2, [sp, #0x64]
	ldr r0, [r2]
	mov r4, sl
	str r0, [r4]
	ldr r5, [sp, #0x60]
	ldrb r0, [r5]
	mov r6, ip
	strb r0, [r6]
	ldr r1, [sp, #0x2c]
	ldrb r0, [r1]
	ldr r2, [sp, #0x54]
	strb r0, [r2]
	ldr r4, [sp, #0x30]
	ldrb r0, [r4]
	ldr r5, [sp, #0x58]
	strb r0, [r5]
	ldr r6, [sp, #0x34]
	ldrb r0, [r6]
	ldr r1, [sp, #0x5c]
	strb r0, [r1]
	mov r2, sp
	ldrb r4, [r2, #0x1c]
	ldr r2, [sp, #0x4c]
	strb r4, [r2]
	ldr r5, [sp, #0x28]
	ldr r2, [r5]
	movs r0, #0x1b
	movs r1, #1
	ldr r6, [sp, #0x40]
	strb r1, [r6]
	ldr r4, [sp, #0x38]
	strb r3, [r4]
	ldr r5, [sp, #0x60]
	strb r0, [r5]
	ldr r6, [sp, #0x64]
	str r2, [r6]
	movs r2, #0
	ldr r0, [sp, #0x20]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x2c]
	strb r0, [r4]
	ldr r5, [sp, #0x30]
	strb r1, [r5]
	ldr r6, [sp, #0x34]
	strb r2, [r6]
	ldr r0, [sp, #0x48]
	str r3, [r0]
	ldr r2, [sp, #0x3c]
	strb r1, [r2]
	movs r0, #6
	ldr r3, [sp, #0x50]
	strb r0, [r3]
_081C04DC:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r4, [sp, #0x44]
	strh r0, [r4]
	movs r0, #0
	b _081C05EA
	.align 2, 0
_081C04EC: .4byte 0x00000482
_081C04F0: .4byte 0x0000054F
_081C04F4: .4byte 0x0000054C
_081C04F8: .4byte 0x0000054D
_081C04FC: .4byte 0x0000054E
_081C0500: .4byte 0x00000541
_081C0504: .4byte 0x000005BC
_081C0508: .4byte 0x00000542
_081C050C: .4byte 0x0203B400
_081C0510: .4byte 0x030046B8
_081C0514: .4byte 0x000003FF
_081C0518:
	mov sb, sp
	ldr r6, _081C0554 @ =0x030046A4
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	ldr r0, [r6]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Div
	mov r8, r0
	lsls r4, r4, #8
	adds r4, #0x80
	mov r0, sp
	strh r4, [r0]
	adds r0, r5, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C0558
	adds r0, #4
	b _081C0562
	.align 2, 0
_081C0554: .4byte 0x030046A4
_081C0558:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081C0562:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	mov r4, sb
	strh r0, [r4, #2]
	mov r5, r8
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r4, #4]
	ldr r6, _081C0598 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081C05A0
	ldr r0, _081C059C @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C05CA
	.align 2, 0
_081C0598: .4byte 0x000004A4
_081C059C: .4byte 0xFFFFFDFF
_081C05A0:
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081C05C0
	cmp r0, #2
	beq _081C05BC
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C05BC:
	movs r0, #1
	b _081C05CC
_081C05C0:
	ldr r0, _081C05E0 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C05CA:
	movs r0, #0
_081C05CC:
	cmp r0, #0
	bne _081C05E8
	ldr r4, _081C05E4 @ =0x000005C4
	adds r0, r7, r4
_081C05D4:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _081C05EA
	.align 2, 0
_081C05E0: .4byte 0xFFFFFDFF
_081C05E4: .4byte 0x000005C4
_081C05E8:
	movs r0, #1
_081C05EA:
	cmp r0, #0
	bne _081C05F0
	b _081C07CE
_081C05F0:
	ldr r5, _081C05FC @ =0x00000482
	adds r1, r7, r5
	movs r0, #2
	strh r0, [r1]
	b _081C07CE
	.align 2, 0
_081C05FC: .4byte 0x00000482
_081C0600:
	movs r5, #0x80
	lsls r5, r5, #2
	ands r2, r5
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r4, r7, r6
	cmp r2, #0
	beq _081C0658
	movs r1, #0x80
	lsls r1, r1, #0xe
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081C0648
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _081C06D4 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	mov r1, sl
	ldrh r0, [r1]
	bics r0, r5
	strh r0, [r1]
	movs r2, #0x87
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r5, #0
	strb r5, [r0]
	adds r6, #0xa6
	adds r0, r7, r6
	strh r3, [r0]
	ldr r1, _081C06D8 @ =0x00000202
	adds r0, r7, r1
	strh r3, [r0]
_081C0648:
	ldr r2, _081C06DC @ =0x000001DF
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl Enemy_SetEmote
_081C0658:
	movs r1, #0x10
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r3, _081C06E0 @ =0x00000482
	adds r1, r7, r3
	movs r4, #0
	movs r0, #1
	strh r0, [r1]
	movs r5, #0xb4
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r3, [r0]
	movs r5, #7
	movs r1, #0x3c
	movs r6, #0xab
	lsls r6, r6, #3
	adds r2, r7, r6
	subs r6, #4
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _081C06E4 @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _081C06E8 @ =0x00000552
	adds r0, r7, r3
	strb r5, [r0]
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r5, [r0]
	adds r2, r7, #0
	adds r2, #0x9c
	ldr r0, [r2, #8]
	ldrh r1, [r0]
	strh r1, [r5]
	ldr r0, [r2, #8]
	ldrh r0, [r0, #2]
	strh r0, [r5, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081C06D0
	cmp r1, #0
	blt _081C06D0
	ldr r0, _081C06EC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081C06D0
	ldr r0, _081C06F0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081C06F4
_081C06D0:
	movs r4, #0
	b _081C0702
	.align 2, 0
_081C06D4: .4byte 0xFEFFFFFF
_081C06D8: .4byte 0x00000202
_081C06DC: .4byte 0x000001DF
_081C06E0: .4byte 0x00000482
_081C06E4: .4byte 0x00000551
_081C06E8: .4byte 0x00000552
_081C06EC: .4byte 0x030046A8
_081C06F0: .4byte 0x030046AC
_081C06F4:
	ldr r0, _081C0714 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081C0702:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081C0718
	adds r0, #4
	b _081C0724
	.align 2, 0
_081C0714: .4byte 0x030046A4
_081C0718:
	ldr r0, _081C0738 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081C0724:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081C073C
	cmp r2, #2
	beq _081C0740
	b _081C0744
	.align 2, 0
_081C0738: .4byte 0x030046A4
_081C073C:
	ldrb r0, [r5, #4]
	b _081C0742
_081C0740:
	ldrb r0, [r5]
_081C0742:
	subs r1, r1, r0
_081C0744:
	strh r1, [r5, #2]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r2, r7, r5
	ldr r1, [r2]
	movs r0, #1
	strh r0, [r1, #6]
	ldr r6, _081C0774 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	ldr r5, [r2]
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	adds r2, r5, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081C077C
	ldr r0, _081C0778 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081C07A6
	.align 2, 0
_081C0774: .4byte 0x000004A4
_081C0778: .4byte 0xFFFFFDFF
_081C077C:
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	adds r2, r5, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081C079C
	cmp r0, #2
	beq _081C0798
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081C0798:
	movs r0, #1
	b _081C07A8
_081C079C:
	ldr r0, _081C07BC @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081C07A6:
	movs r0, #0
_081C07A8:
	cmp r0, #0
	bne _081C07CE
	ldr r4, _081C07C0 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081C07CE
	.align 2, 0
_081C07BC: .4byte 0xFFFFFDFF
_081C07C0: .4byte 0x000005C4

_081C07C4:
	ldr r5, _081C07E0 @ =0x00000484
	adds r1, r7, r5
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081C07CE:
	add sp, #0x68
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081C07E0: .4byte 0x00000484
