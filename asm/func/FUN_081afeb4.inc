	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x8c
	adds r7, r0, #0
	adds r4, r1, #0
	ldr r0, _081AFED8 @ =0x0000046D
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081AFEDC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081AFEDE
	.align 2, 0
_081AFED8: .4byte 0x0000046D
_081AFEDC:
	movs r0, #0
_081AFEDE:
	cmp r0, #0
	beq _081AFEEA
	adds r0, r7, #0
	movs r1, #3
	bl Enemy_PlayAnim
_081AFEEA:
	movs r0, #0x10
	movs r2, #0xc1
	lsls r2, r2, #1
	adds r1, r7, r2
	ldrh r2, [r1]
	orrs r0, r2
	strh r0, [r1]
	adds r5, r1, #0
	cmp r4, #0x11
	bgt _081AFF1E
	ldr r0, [r7, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	ldrh r4, [r3, #8]
	cmp r4, #0
	bne _081AFF1E
	ldrh r1, [r3, #0xe]
	ldrb r2, [r3, #7]
	rsbs r0, r2, #0
	orrs r0, r2
	lsrs r0, r0, #0x1f
	cmp r1, r0
	bne _081AFF1E
	cmp r2, #1
	beq _081AFF1E
	strh r4, [r3, #0xe]
_081AFF1E:
	ldr r3, _081AFFAC @ =0x0000046E
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _081AFF2C
	bl _081B083C
_081AFF2C:
	ldr r4, _081AFFB0 @ =0x0000046B
	adds r0, r7, r4
	movs r4, #0
	movs r1, #1
	mov sl, r1
	mov r2, sl
	strb r2, [r0]
	movs r0, #2
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r1, r7, r3
	ldrh r2, [r1]
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	str r1, [sp, #0x78]
	cmp r3, #0
	beq _081AFFC4
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r1, [r0]
	ldr r3, _081AFFB4 @ =0x00000469
	adds r0, r7, r3
	strb r4, [r0]
	ldr r1, _081AFFB8 @ =0x0000046A
	adds r0, r7, r1
	strb r4, [r0]
	adds r2, #0x1c
	adds r0, r7, r2
	str r4, [r0]
	adds r3, #3
	adds r0, r7, r3
	mov r1, sl
	strb r1, [r0]
	ldr r2, _081AFFBC @ =0x00000594
	adds r0, r7, r2
	ldr r2, [r0]
	movs r1, #7
	adds r3, #1
	adds r0, r7, r3
	mov r3, sl
	strb r3, [r0]
	ldr r3, _081AFFB0 @ =0x0000046B
	adds r0, r7, r3
	strb r4, [r0]
	adds r3, #0xe8
	adds r0, r7, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r4, [r0]
	ldr r0, _081AFFC0 @ =0xFFFFF67C
	ldrh r1, [r5]
	ands r0, r1
	strh r0, [r5]
	bl _081B083C
	.align 2, 0
_081AFFAC: .4byte 0x0000046E
_081AFFB0: .4byte 0x0000046B
_081AFFB4: .4byte 0x00000469
_081AFFB8: .4byte 0x0000046A
_081AFFBC: .4byte 0x00000594
_081AFFC0: .4byte 0xFFFFF67C
_081AFFC4:
	movs r0, #0x80
	ands r2, r0
	lsls r0, r2, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	bne _081AFFD2
	b _081B05F4
_081AFFD2:
	adds r0, r7, #0
	movs r1, #0
	str r3, [sp, #0x88]
	bl Enemy_PlayAnim
	movs r0, #3
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #8]
	strb r0, [r4]
	ldr r5, _081B00D0 @ =0x00000469
	adds r5, r7, r5
	str r5, [sp, #0xc]
	mov r0, sl
	strb r0, [r5]
	ldr r1, _081B00D4 @ =0x0000046A
	adds r1, r7, r1
	str r1, [sp, #0x10]
	ldr r3, [sp, #0x88]
	strb r3, [r1]
	ldr r2, _081B00D8 @ =0x00000484
	adds r2, r7, r2
	str r2, [sp, #0x14]
	str r3, [r2]
	ldr r4, _081B00DC @ =0x0000046C
	adds r4, r7, r4
	str r4, [sp, #0x18]
	strb r0, [r4]
	ldr r1, _081B00E0 @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r5, _081B00E4 @ =0x0000046D
	adds r6, r7, r5
	mov r2, sl
	strb r2, [r6]
	ldr r4, _081B00E8 @ =0x0000046B
	adds r4, r7, r4
	str r4, [sp, #0x1c]
	strb r3, [r4]
	adds r5, #0xe6
	adds r5, r5, r7
	mov ip, r5
	strb r0, [r5]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r0, r7
	mov sb, r0
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r1, r7
	mov r8, r1
	movs r4, #0
	strh r3, [r1]
	movs r2, #0xb7
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _081B00EC @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _081B00F0 @ =0x00000552
	adds r0, r7, r3
	movs r4, #0xc
	strb r4, [r0]
	subs r5, #0xac
	adds r3, r7, r5
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
	str r6, [sp, #0x54]
	ldr r0, [sp, #8]
	str r0, [sp, #0x40]
	ldr r0, [sp, #0xc]
	str r0, [sp, #0x44]
	ldr r0, [sp, #0x10]
	str r0, [sp, #0x48]
	ldr r0, [sp, #0x14]
	str r0, [sp, #0x5c]
	ldr r0, [sp, #0x18]
	str r0, [sp, #0x50]
	ldr r0, [sp, #0x1c]
	str r0, [sp, #0x4c]
	mov r0, ip
	str r0, [sp, #0x74]
	mov r0, sb
	str r0, [sp, #0x7c]
	mov r0, r8
	str r0, [sp, #0x80]
	adds r6, r3, #0
	mov r8, r2
	cmp r4, #0
	blt _081B00CC
	cmp r1, #0
	blt _081B00CC
	ldr r0, _081B00F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _081B00CC
	ldr r0, _081B00F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B00FC
_081B00CC:
	movs r4, #0
	b _081B010A
	.align 2, 0
_081B00D0: .4byte 0x00000469
_081B00D4: .4byte 0x0000046A
_081B00D8: .4byte 0x00000484
_081B00DC: .4byte 0x0000046C
_081B00E0: .4byte Enemy_WaitPendingState
_081B00E4: .4byte 0x0000046D
_081B00E8: .4byte 0x0000046B
_081B00EC: .4byte 0x00000551
_081B00F0: .4byte 0x00000552
_081B00F4: .4byte 0x030046A8
_081B00F8: .4byte 0x030046AC
_081B00FC:
	ldr r0, _081B011C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_081B010A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B0120
	adds r0, #4
	b _081B012C
	.align 2, 0
_081B011C: .4byte 0x030046A4
_081B0120:
	ldr r0, _081B0140 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B012C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B0144
	cmp r2, #2
	beq _081B0148
	b _081B014C
	.align 2, 0
_081B0140: .4byte 0x030046A4
_081B0144:
	ldrb r0, [r5, #4]
	b _081B014A
_081B0148:
	ldrb r0, [r5]
_081B014A:
	subs r1, r1, r0
_081B014C:
	strh r1, [r5, #2]
	ldr r0, _081B0160 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081B0164
	movs r0, #1
	b _081B0166
	.align 2, 0
_081B0160: .4byte 0x030047A4
_081B0164:
	movs r0, #0
_081B0166:
	cmp r0, #0
	beq _081B01A4
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081B0186
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _081B0182
	adds r2, r0, #0
_081B0182:
	cmp r2, #0
	bge _081B0190
_081B0186:
	ldr r2, _081B018C @ =0x000005C4
	adds r0, r7, r2
	b _081B05E2
	.align 2, 0
_081B018C: .4byte 0x000005C4
_081B0190:
	ldr r1, _081B01A0 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _081B01EC
	.align 2, 0
_081B01A0: .4byte 0x03002BE0
_081B01A4:
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
	blt _081B01D0
	cmp r1, #0
	blt _081B01D0
	ldr r0, _081B01D4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B01D0
	ldr r0, _081B01D8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B01DC
_081B01D0:
	movs r5, #0
	b _081B01EA
	.align 2, 0
_081B01D4: .4byte 0x030046A8
_081B01D8: .4byte 0x030046AC
_081B01DC:
	ldr r0, _081B027C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081B01EA:
	movs r2, #0
_081B01EC:
	ldr r4, _081B0280 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _081B020C
	ldr r1, _081B0284 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _081B020C
	b _081B0520
_081B020C:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x78]
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _081B0220
	b _081B083C
_081B0220:
	ldr r0, _081B0288 @ =0x00000222
	adds r2, r7, r0
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	movs r5, #0
	strh r0, [r2]
	movs r1, #0x80
	ldr r3, [sp, #0x78]
	ldrh r0, [r3]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov sb, r2
	cmp r3, #0
	beq _081B028C
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #0x1a
	movs r2, #1
	ldr r3, [sp, #0x54]
	strb r2, [r3]
	ldr r3, [sp, #0x4c]
	strb r5, [r3]
	ldr r3, [sp, #0x74]
	strb r0, [r3]
	ldr r0, [sp, #0x7c]
	str r1, [r0]
	ldr r1, [sp, #0x80]
	strh r4, [r1]
	movs r0, #0xc
	ldr r3, [sp, #0x40]
	strb r5, [r3]
	ldr r1, [sp, #0x44]
	strb r5, [r1]
	ldr r3, [sp, #0x48]
	strb r0, [r3]
	ldr r5, [sp, #0x5c]
	str r4, [r5]
	ldr r0, [sp, #0x50]
	strb r2, [r0]
	b _081B03DA
	.align 2, 0
_081B027C: .4byte 0x030046A4
_081B0280: .4byte 0x00000256
_081B0284: .4byte 0x03002BE0
_081B0288: .4byte 0x00000222
_081B028C:
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r1, [r0]
	movs r0, #1
	ldr r2, [sp, #0x54]
	strb r0, [r2]
	ldr r4, [sp, #0x4c]
	strb r5, [r4]
	ldr r2, [sp, #0x74]
	strb r0, [r2]
	ldr r4, [sp, #0x7c]
	str r1, [r4]
	ldr r1, [sp, #0x80]
	strh r3, [r1]
	movs r1, #5
	ldr r2, [sp, #0x40]
	strb r5, [r2]
	ldr r4, [sp, #0x44]
	strb r5, [r4]
	ldr r5, [sp, #0x48]
	strb r1, [r5]
	ldr r1, [sp, #0x5c]
	str r3, [r1]
	ldr r2, [sp, #0x50]
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
	blt _081B02F0
	cmp r1, #0
	blt _081B02F0
	ldr r0, _081B02F4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B02F0
	ldr r0, _081B02F8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B02FC
_081B02F0:
	movs r4, #0
	b _081B030A
	.align 2, 0
_081B02F4: .4byte 0x030046A8
_081B02F8: .4byte 0x030046AC
_081B02FC:
	ldr r0, _081B031C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B030A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B0320
	adds r0, #4
	b _081B032C
	.align 2, 0
_081B031C: .4byte 0x030046A4
_081B0320:
	ldr r0, _081B0340 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B032C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B0344
	cmp r2, #2
	beq _081B0348
	b _081B034C
	.align 2, 0
_081B0340: .4byte 0x030046A4
_081B0344:
	ldrb r0, [r5, #4]
	b _081B034A
_081B0348:
	ldrb r0, [r5]
_081B034A:
	subs r1, r1, r0
_081B034C:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081B0374
	cmp r1, #0
	blt _081B0374
	ldr r0, _081B0378 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B0374
	ldr r0, _081B037C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B0380
_081B0374:
	movs r4, #0
	b _081B038E
	.align 2, 0
_081B0378: .4byte 0x030046A8
_081B037C: .4byte 0x030046AC
_081B0380:
	ldr r0, _081B03A0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B038E:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B03A4
	adds r0, #4
	b _081B03B0
	.align 2, 0
_081B03A0: .4byte 0x030046A4
_081B03A4:
	ldr r0, _081B03C4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B03B0:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081B03C8
	cmp r3, #2
	beq _081B03CC
	b _081B03D0
	.align 2, 0
_081B03C4: .4byte 0x030046A4
_081B03C8:
	ldrb r0, [r5, #4]
	b _081B03CE
_081B03CC:
	ldrb r0, [r5]
_081B03CE:
	subs r2, r2, r0
_081B03D0:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_081B03DA:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x20]
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r5, [sp, #0x78]
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	adds r1, #0x82
	adds r1, r7, r1
	str r1, [sp, #0x58]
	cmp r0, #0
	bne _081B04E4
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081B0404
	movs r0, #1
	b _081B0406
_081B0404:
	movs r0, #0
_081B0406:
	ldr r3, _081B04F4 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x58]
	cmp r0, #0
	bne _081B04E4
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r0, _081B04F8 @ =0x0000054F
	adds r0, r0, r7
	mov ip, r0
	ldr r1, _081B04FC @ =0x0000054C
	adds r1, r7, r1
	str r1, [sp, #0x68]
	ldr r2, _081B0500 @ =0x0000054D
	adds r2, r7, r2
	str r2, [sp, #0x6c]
	ldr r4, _081B0504 @ =0x0000054E
	adds r4, r7, r4
	str r4, [sp, #0x70]
	ldr r5, _081B0508 @ =0x00000541
	adds r5, r7, r5
	str r5, [sp, #0x60]
	ldr r0, _081B050C @ =0x000005BC
	adds r0, r7, r0
	str r0, [sp, #0x84]
	ldr r1, _081B0510 @ =0x00000542
	adds r1, r7, r1
	str r1, [sp, #0x64]
	ldr r6, _081B0514 @ =0x0203B400
	ldr r1, _081B0518 @ =0x030046B8
	ldr r2, _081B051C @ =0x000003FF
	movs r5, #3
	mov r4, r8
_081B0456:
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r5
	lsls r0, r0, #6
	cmp r0, r4
	bne _081B0474
	adds r3, #1
	cmp r3, #3
	ble _081B0456
	mov r0, r8
_081B0474:
	movs r3, #0
	mov r2, sb
	strb r0, [r2]
	ldr r4, [sp, #0x7c]
	ldr r0, [r4]
	mov r5, sl
	str r0, [r5]
	ldr r1, [sp, #0x74]
	ldrb r0, [r1]
	mov r2, ip
	strb r0, [r2]
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	ldr r5, [sp, #0x68]
	strb r0, [r5]
	ldr r1, [sp, #0x44]
	ldrb r0, [r1]
	ldr r2, [sp, #0x6c]
	strb r0, [r2]
	ldr r4, [sp, #0x48]
	ldrb r0, [r4]
	ldr r5, [sp, #0x70]
	strb r0, [r5]
	add r0, sp, #0x20
	ldrb r1, [r0]
	ldr r0, [sp, #0x60]
	strb r1, [r0]
	ldr r1, [sp, #0x84]
	ldr r2, [r1]
	movs r0, #0x1b
	movs r1, #1
	ldr r4, [sp, #0x54]
	strb r1, [r4]
	ldr r5, [sp, #0x4c]
	strb r3, [r5]
	ldr r4, [sp, #0x74]
	strb r0, [r4]
	ldr r5, [sp, #0x7c]
	str r2, [r5]
	movs r2, #0
	ldr r0, [sp, #0x80]
	strh r3, [r0]
	movs r0, #3
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	strb r1, [r5]
	ldr r0, [sp, #0x48]
	strb r2, [r0]
	ldr r2, [sp, #0x5c]
	str r3, [r2]
	ldr r3, [sp, #0x50]
	strb r1, [r3]
	movs r0, #6
	ldr r4, [sp, #0x64]
	strb r0, [r4]
_081B04E4:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r5, [sp, #0x58]
	strh r0, [r5]
	b _081B083C
	.align 2, 0
_081B04F4: .4byte 0x00000482
_081B04F8: .4byte 0x0000054F
_081B04FC: .4byte 0x0000054C
_081B0500: .4byte 0x0000054D
_081B0504: .4byte 0x0000054E
_081B0508: .4byte 0x00000541
_081B050C: .4byte 0x000005BC
_081B0510: .4byte 0x00000542
_081B0514: .4byte 0x0203B400
_081B0518: .4byte 0x030046B8
_081B051C: .4byte 0x000003FF
_081B0520:
	mov sb, sp
	ldr r6, _081B055C @ =0x030046A4
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
	beq _081B0560
	adds r0, #4
	b _081B056A
	.align 2, 0
_081B055C: .4byte 0x030046A4
_081B0560:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081B056A:
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
	ldr r1, _081B05A4 @ =0x000004A4
	adds r0, r7, r1
	ldr r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B05AC
	ldr r0, _081B05A8 @ =0xFFFFFDFF
	ldr r2, [sp, #0x78]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B05D6
	.align 2, 0
_081B05A4: .4byte 0x000004A4
_081B05A8: .4byte 0xFFFFFDFF
_081B05AC:
	adds r0, r4, #0
	adds r1, r5, #0
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B05CC
	cmp r0, #2
	beq _081B05C8
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B05C8:
	movs r0, #1
	b _081B05D8
_081B05CC:
	ldr r0, _081B05EC @ =0xFFFFFDFF
	ldr r3, [sp, #0x78]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B05D6:
	movs r0, #0
_081B05D8:
	cmp r0, #0
	beq _081B05DE
	b _081B083C
_081B05DE:
	ldr r4, _081B05F0 @ =0x000005C4
	adds r0, r7, r4
_081B05E2:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _081B083C
	.align 2, 0
_081B05EC: .4byte 0xFFFFFDFF
_081B05F0: .4byte 0x000005C4
_081B05F4:
	adds r0, r7, #0
	movs r1, #0
	bl Enemy_PlayAnim
	movs r0, #3
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x24]
	strb r0, [r1]
	ldr r2, _081B070C @ =0x00000469
	adds r2, r7, r2
	str r2, [sp, #0x28]
	mov r3, sl
	strb r3, [r2]
	ldr r4, _081B0710 @ =0x0000046A
	adds r4, r7, r4
	str r4, [sp, #0x2c]
	strb r5, [r4]
	ldr r0, _081B0714 @ =0x00000484
	adds r0, r7, r0
	str r0, [sp, #0x30]
	str r5, [r0]
	ldr r1, _081B0718 @ =0x0000046C
	adds r1, r7, r1
	str r1, [sp, #0x34]
	strb r3, [r1]
	ldr r1, _081B071C @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r2, _081B0720 @ =0x0000046D
	adds r6, r7, r2
	strb r3, [r6]
	ldr r3, _081B0724 @ =0x0000046B
	adds r3, r7, r3
	str r3, [sp, #0x38]
	strb r5, [r3]
	ldr r4, _081B0728 @ =0x00000553
	adds r4, r7, r4
	str r4, [sp, #0x3c]
	strb r0, [r4]
	movs r0, #0xaf
	lsls r0, r0, #3
	adds r0, r0, r7
	mov sb, r0
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r1, r1, r7
	mov r8, r1
	movs r4, #0
	strh r5, [r1]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldr r3, [r0]
	movs r1, #0x3c
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	subs r5, #4
	adds r0, r7, r5
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r4, [r0]
	ldr r2, _081B072C @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _081B0730 @ =0x00000552
	adds r0, r7, r3
	movs r4, #7
	strb r4, [r0]
	subs r5, #0xd2
	adds r0, r7, r5
	mov r1, sl
	strh r1, [r0]
	movs r2, #0x10
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x21
	rsbs r0, r0, #0
	ldr r4, [sp, #0x78]
	ldrh r1, [r4]
	ands r0, r1
	strh r0, [r4]
	adds r5, #0x26
	adds r0, r7, r5
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
	str r6, [sp, #0x54]
	ldr r0, [sp, #0x24]
	str r0, [sp, #0x40]
	ldr r3, [sp, #0x28]
	str r3, [sp, #0x44]
	ldr r4, [sp, #0x2c]
	str r4, [sp, #0x48]
	ldr r0, [sp, #0x30]
	str r0, [sp, #0x5c]
	ldr r3, [sp, #0x34]
	str r3, [sp, #0x50]
	ldr r4, [sp, #0x38]
	str r4, [sp, #0x4c]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #0x74]
	mov r3, sb
	str r3, [sp, #0x7c]
	mov r4, r8
	str r4, [sp, #0x80]
	cmp r2, #0
	blt _081B0706
	cmp r1, #0
	blt _081B0706
	ldr r0, _081B0734 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081B0706
	ldr r0, _081B0738 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081B073C
_081B0706:
	movs r4, #0
	b _081B074A
	.align 2, 0
_081B070C: .4byte 0x00000469
_081B0710: .4byte 0x0000046A
_081B0714: .4byte 0x00000484
_081B0718: .4byte 0x0000046C
_081B071C: .4byte Enemy_WaitPendingState
_081B0720: .4byte 0x0000046D
_081B0724: .4byte 0x0000046B
_081B0728: .4byte 0x00000553
_081B072C: .4byte 0x00000551
_081B0730: .4byte 0x00000552
_081B0734: .4byte 0x030046A8
_081B0738: .4byte 0x030046AC
_081B073C:
	ldr r0, _081B075C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_081B074A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _081B0760
	adds r0, #4
	b _081B076C
	.align 2, 0
_081B075C: .4byte 0x030046A4
_081B0760:
	ldr r0, _081B0780 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081B076C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081B0784
	cmp r2, #2
	beq _081B0788
	b _081B078C
	.align 2, 0
_081B0780: .4byte 0x030046A4
_081B0784:
	ldrb r0, [r5, #4]
	b _081B078A
_081B0788:
	ldrb r0, [r5]
_081B078A:
	subs r1, r1, r0
_081B078C:
	strh r1, [r5, #2]
	ldr r5, _081B07BC @ =0x000004A4
	adds r0, r7, r5
	ldr r5, [r0]
	adds r6, r7, #0
	adds r6, #8
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r4, [r0]
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _081B07C4
	ldr r0, _081B07C0 @ =0xFFFFFDFF
	ldr r2, [sp, #0x78]
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _081B07EE
	.align 2, 0
_081B07BC: .4byte 0x000004A4
_081B07C0: .4byte 0xFFFFFDFF
_081B07C4:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _081B07E4
	cmp r0, #2
	beq _081B07E0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_081B07E0:
	movs r0, #1
	b _081B07F0
_081B07E4:
	ldr r0, _081B0828 @ =0xFFFFFDFF
	ldr r3, [sp, #0x78]
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_081B07EE:
	movs r0, #0
_081B07F0:
	adds r3, r0, #0
	cmp r3, #0
	bne _081B0830
	ldr r0, _081B082C @ =Enemy_ClearStateBegun
	movs r2, #1
	ldr r4, [sp, #0x54]
	strb r2, [r4]
	ldr r5, [sp, #0x4c]
	strb r3, [r5]
	ldr r1, [sp, #0x74]
	strb r3, [r1]
	ldr r4, [sp, #0x7c]
	str r0, [r4]
	movs r1, #0
	ldr r5, [sp, #0x80]
	strh r3, [r5]
	movs r0, #3
	ldr r4, [sp, #0x40]
	strb r0, [r4]
	ldr r5, [sp, #0x44]
	strb r1, [r5]
	ldr r0, [sp, #0x48]
	strb r1, [r0]
	ldr r1, [sp, #0x5c]
	str r3, [r1]
	ldr r3, [sp, #0x50]
	strb r2, [r3]
	b _081B083C
	.align 2, 0
_081B0828: .4byte 0xFFFFFDFF
_081B082C: .4byte Enemy_ClearStateBegun
_081B0830:
	movs r4, #0x95
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #6]
_081B083C:
	add sp, #0x8c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
