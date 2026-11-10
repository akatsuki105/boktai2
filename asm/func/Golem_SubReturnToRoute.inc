	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x68
	adds r7, r0, #0
	ldr r0, _0811F174 @ =0x0000046C
	adds r1, r7, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0811F068
	movs r0, #0
	strb r0, [r1]
_0811F068:
	adds r0, r7, #0
	bl Golem_TryChaseHitTarget
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _0811F07A
	bl _0811F8F6
_0811F07A:
	ldr r1, _0811F178 @ =0x0000046B
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0811F088
	bl _0811F8EC
_0811F088:
	movs r0, #3
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #8]
	strb r0, [r2]
	ldr r4, _0811F17C @ =0x00000469
	adds r4, r7, r4
	str r4, [sp, #0xc]
	strb r1, [r4]
	ldr r5, _0811F180 @ =0x0000046A
	adds r5, r7, r5
	str r5, [sp, #0x10]
	strb r3, [r5]
	ldr r6, _0811F184 @ =0x00000484
	adds r6, r7, r6
	str r6, [sp, #0x14]
	str r3, [r6]
	ldr r0, _0811F174 @ =0x0000046C
	adds r0, r0, r7
	mov sb, r0
	strb r1, [r0]
	ldr r2, _0811F188 @ =Enemy_WaitPendingState
	movs r0, #0xe
	ldr r4, _0811F18C @ =0x0000046D
	adds r4, r7, r4
	str r4, [sp, #0x18]
	strb r1, [r4]
	ldr r5, _0811F178 @ =0x0000046B
	adds r5, r5, r7
	mov sl, r5
	strb r3, [r5]
	ldr r6, _0811F190 @ =0x00000553
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
	ldr r2, _0811F194 @ =0x000004A4
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
	bne _0811F130
	b _0811F728
_0811F130:
	movs r1, #0xb7
	lsls r1, r1, #3
	adds r0, r7, r1
	ldr r3, [r0]
	movs r4, #0xc
	movs r1, #0x1e
	movs r5, #0xab
	lsls r5, r5, #3
	adds r2, r7, r5
	ldr r6, _0811F198 @ =0x00000554
	adds r0, r7, r6
	str r1, [r0]
	str r3, [r2]
	movs r1, #0xaa
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r2, #0
	strb r2, [r0]
	ldr r3, _0811F19C @ =0x00000551
	adds r0, r7, r3
	strb r2, [r0]
	subs r5, #6
	adds r0, r7, r5
	strb r4, [r0]
	ldr r0, _0811F1A0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811F1A4
	movs r0, #1
	b _0811F1A6
	.align 2, 0
_0811F174: .4byte 0x0000046C
_0811F178: .4byte 0x0000046B
_0811F17C: .4byte 0x00000469
_0811F180: .4byte 0x0000046A
_0811F184: .4byte 0x00000484
_0811F188: .4byte Enemy_WaitPendingState
_0811F18C: .4byte 0x0000046D
_0811F190: .4byte 0x00000553
_0811F194: .4byte 0x000004A4
_0811F198: .4byte 0x00000554
_0811F19C: .4byte 0x00000551
_0811F1A0: .4byte 0x030047A4
_0811F1A4:
	movs r0, #0
_0811F1A6:
	cmp r0, #0
	beq _0811F1BA
	adds r0, r7, #0
	bl Enemy_TargetNearestLinkPlayer
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0811F1B8
	b _0811F8F6
_0811F1B8:
	b _0811F1C8
_0811F1BA:
	movs r6, #0xec
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, _0811F208 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
_0811F1C8:
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
	blt _0811F204
	cmp r1, #0
	blt _0811F204
	ldr r0, _0811F20C @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _0811F204
	ldr r0, _0811F210 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811F214
_0811F204:
	movs r4, #0
	b _0811F222
	.align 2, 0
_0811F208: .4byte 0x03002BE0
_0811F20C: .4byte 0x030046A8
_0811F210: .4byte 0x030046AC
_0811F214:
	ldr r0, _0811F234 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_0811F222:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811F238
	adds r0, #4
	b _0811F244
	.align 2, 0
_0811F234: .4byte 0x030046A4
_0811F238:
	ldr r0, _0811F258 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811F244:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811F25C
	cmp r2, #2
	beq _0811F260
	b _0811F264
	.align 2, 0
_0811F258: .4byte 0x030046A4
_0811F25C:
	ldrb r0, [r5, #4]
	b _0811F262
_0811F260:
	ldrb r0, [r5]
_0811F262:
	subs r1, r1, r0
_0811F264:
	strh r1, [r5, #2]
	ldr r0, _0811F278 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811F27C
	movs r0, #1
	b _0811F27E
	.align 2, 0
_0811F278: .4byte 0x030047A4
_0811F27C:
	movs r0, #0
_0811F27E:
	cmp r0, #0
	beq _0811F2BC
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0811F29E
	ldrb r0, [r1, #4]
	movs r2, #1
	rsbs r2, r2, #0
	cmp r0, #3
	bhi _0811F29A
	adds r2, r0, #0
_0811F29A:
	cmp r2, #0
	bge _0811F2A8
_0811F29E:
	ldr r2, _0811F2A4 @ =0x000005C4
	adds r0, r7, r2
	b _0811F6FC
	.align 2, 0
_0811F2A4: .4byte 0x000005C4
_0811F2A8:
	ldr r1, _0811F2B8 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x3c]
	ldrh r5, [r0, #6]
	b _0811F304
	.align 2, 0
_0811F2B8: .4byte 0x03002BE0
_0811F2BC:
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
	blt _0811F2E8
	cmp r1, #0
	blt _0811F2E8
	ldr r0, _0811F2EC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811F2E8
	ldr r0, _0811F2F0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811F2F4
_0811F2E8:
	movs r5, #0
	b _0811F302
	.align 2, 0
_0811F2EC: .4byte 0x030046A8
_0811F2F0: .4byte 0x030046AC
_0811F2F4:
	ldr r0, _0811F33C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_0811F302:
	movs r2, #0
_0811F304:
	ldr r4, _0811F340 @ =0x00000256
	adds r0, r7, r4
	ldrh r0, [r0]
	cmp r5, r0
	beq _0811F324
	ldr r1, _0811F344 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _0811F324
	b _0811F640
_0811F324:
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	cmp r4, #0
	beq _0811F348
	movs r0, #0
	b _0811F712
	.align 2, 0
_0811F33C: .4byte 0x030046A4
_0811F340: .4byte 0x00000256
_0811F344: .4byte 0x03002BE0
_0811F348:
	ldr r0, _0811F3A4 @ =0x00000222
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
	beq _0811F3A8
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
	b _0811F4F6
	.align 2, 0
_0811F3A4: .4byte 0x00000222
_0811F3A8:
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
	blt _0811F40C
	cmp r1, #0
	blt _0811F40C
	ldr r0, _0811F410 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811F40C
	ldr r0, _0811F414 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811F418
_0811F40C:
	movs r4, #0
	b _0811F426
	.align 2, 0
_0811F410: .4byte 0x030046A8
_0811F414: .4byte 0x030046AC
_0811F418:
	ldr r0, _0811F438 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811F426:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811F43C
	adds r0, #4
	b _0811F448
	.align 2, 0
_0811F438: .4byte 0x030046A4
_0811F43C:
	ldr r0, _0811F45C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811F448:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811F460
	cmp r2, #2
	beq _0811F464
	b _0811F468
	.align 2, 0
_0811F45C: .4byte 0x030046A4
_0811F460:
	ldrb r0, [r5, #4]
	b _0811F466
_0811F464:
	ldrb r0, [r5]
_0811F466:
	subs r1, r1, r0
_0811F468:
	strh r1, [r5, #2]
	ldr r0, [r6]
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0811F490
	cmp r1, #0
	blt _0811F490
	ldr r0, _0811F494 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811F490
	ldr r0, _0811F498 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811F49C
_0811F490:
	movs r4, #0
	b _0811F4AA
	.align 2, 0
_0811F494: .4byte 0x030046A8
_0811F498: .4byte 0x030046AC
_0811F49C:
	ldr r0, _0811F4BC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811F4AA:
	ldr r5, [r6]
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811F4C0
	adds r0, #4
	b _0811F4CC
	.align 2, 0
_0811F4BC: .4byte 0x030046A4
_0811F4C0:
	ldr r0, _0811F4E0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811F4CC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _0811F4E4
	cmp r3, #2
	beq _0811F4E8
	b _0811F4EC
	.align 2, 0
_0811F4E0: .4byte 0x030046A4
_0811F4E4:
	ldrb r0, [r5, #4]
	b _0811F4EA
_0811F4E8:
	ldrb r0, [r5]
_0811F4EA:
	subs r2, r2, r0
_0811F4EC:
	ldr r0, [r6]
	movs r1, #0
	strh r2, [r0, #2]
	ldr r0, [r6]
	strh r1, [r0, #6]
_0811F4F6:
	ldrb r4, [r7, #5]
	str r4, [sp, #0x1c]
	movs r1, #0x80
	lsls r1, r1, #3
	mov r5, sl
	ldrh r0, [r5]
	ands r0, r1
	mov r8, r4
	ldr r6, _0811F520 @ =0x00000482
	adds r6, r7, r6
	str r6, [sp, #0x44]
	cmp r0, #0
	bne _0811F604
	movs r1, #4
	mov r2, sb
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0811F524
	movs r0, #1
	b _0811F526
	.align 2, 0
_0811F520: .4byte 0x00000482
_0811F524:
	movs r0, #0
_0811F526:
	ldr r3, _0811F614 @ =0x00000482
	adds r3, r7, r3
	str r3, [sp, #0x44]
	cmp r0, #0
	bne _0811F604
	movs r3, #0
	movs r4, #0xa8
	lsls r4, r4, #3
	adds r4, r4, r7
	mov sb, r4
	movs r5, #0xa9
	lsls r5, r5, #3
	adds r5, r5, r7
	mov sl, r5
	ldr r6, _0811F618 @ =0x0000054F
	adds r6, r6, r7
	mov ip, r6
	ldr r0, _0811F61C @ =0x0000054C
	adds r0, r7, r0
	str r0, [sp, #0x54]
	ldr r1, _0811F620 @ =0x0000054D
	adds r1, r7, r1
	str r1, [sp, #0x58]
	ldr r2, _0811F624 @ =0x0000054E
	adds r2, r7, r2
	str r2, [sp, #0x5c]
	ldr r4, _0811F628 @ =0x00000541
	adds r4, r7, r4
	str r4, [sp, #0x4c]
	ldr r5, _0811F62C @ =0x000005BC
	adds r5, r7, r5
	str r5, [sp, #0x28]
	ldr r6, _0811F630 @ =0x00000542
	adds r6, r7, r6
	str r6, [sp, #0x50]
	ldr r6, _0811F634 @ =0x0203B400
	ldr r1, _0811F638 @ =0x030046B8
	ldr r5, _0811F63C @ =0x000003FF
	movs r2, #3
	mov r4, r8
_0811F576:
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
	bne _0811F594
	adds r3, #1
	cmp r3, #3
	ble _0811F576
	mov r0, r8
_0811F594:
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
_0811F604:
	adds r0, r7, #0
	bl Enemy_StepToFloorEdge
	movs r0, #2
	ldr r4, [sp, #0x44]
	strh r0, [r4]
	movs r0, #0
	b _0811F712
	.align 2, 0
_0811F614: .4byte 0x00000482
_0811F618: .4byte 0x0000054F
_0811F61C: .4byte 0x0000054C
_0811F620: .4byte 0x0000054D
_0811F624: .4byte 0x0000054E
_0811F628: .4byte 0x00000541
_0811F62C: .4byte 0x000005BC
_0811F630: .4byte 0x00000542
_0811F634: .4byte 0x0203B400
_0811F638: .4byte 0x030046B8
_0811F63C: .4byte 0x000003FF
_0811F640:
	mov sb, sp
	ldr r6, _0811F67C @ =0x030046A4
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
	beq _0811F680
	adds r0, #4
	b _0811F68A
	.align 2, 0
_0811F67C: .4byte 0x030046A4
_0811F680:
	ldr r0, [r6]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_0811F68A:
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
	ldr r6, _0811F6C0 @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	mov r2, sp
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0811F6C8
	ldr r0, _0811F6C4 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0811F6F2
	.align 2, 0
_0811F6C0: .4byte 0x000004A4
_0811F6C4: .4byte 0xFFFFFDFF
_0811F6C8:
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	mov r2, sp
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0811F6E8
	cmp r0, #2
	beq _0811F6E4
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811F6E4:
	movs r0, #1
	b _0811F6F4
_0811F6E8:
	ldr r0, _0811F708 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0811F6F2:
	movs r0, #0
_0811F6F4:
	cmp r0, #0
	bne _0811F710
	ldr r4, _0811F70C @ =0x000005C4
	adds r0, r7, r4
_0811F6FC:
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	movs r0, #0
	b _0811F712
	.align 2, 0
_0811F708: .4byte 0xFFFFFDFF
_0811F70C: .4byte 0x000005C4
_0811F710:
	movs r0, #1
_0811F712:
	cmp r0, #0
	bne _0811F718
	b _0811F8F6
_0811F718:
	ldr r5, _0811F724 @ =0x00000482
	adds r1, r7, r5
	movs r0, #2
	strh r0, [r1]
	b _0811F8F6
	.align 2, 0
_0811F724: .4byte 0x00000482
_0811F728:
	movs r5, #0x80
	lsls r5, r5, #2
	ands r2, r5
	movs r6, #0xbc
	lsls r6, r6, #1
	adds r4, r7, r6
	cmp r2, #0
	beq _0811F780
	movs r1, #0x80
	lsls r1, r1, #0xe
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0811F770
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r7, r0
	ldr r1, _0811F7FC @ =0xFEFFFFFF
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
	ldr r1, _0811F800 @ =0x00000202
	adds r0, r7, r1
	strh r3, [r0]
_0811F770:
	ldr r2, _0811F804 @ =0x000001DF
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	movs r2, #2
	bl Enemy_SetEmote
_0811F780:
	movs r1, #0x10
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r3, _0811F808 @ =0x00000482
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
	ldr r2, _0811F80C @ =0x00000551
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _0811F810 @ =0x00000552
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
	blt _0811F7F8
	cmp r1, #0
	blt _0811F7F8
	ldr r0, _0811F814 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0811F7F8
	ldr r0, _0811F818 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0811F81C
_0811F7F8:
	movs r4, #0
	b _0811F82A
	.align 2, 0
_0811F7FC: .4byte 0xFEFFFFFF
_0811F800: .4byte 0x00000202
_0811F804: .4byte 0x000001DF
_0811F808: .4byte 0x00000482
_0811F80C: .4byte 0x00000551
_0811F810: .4byte 0x00000552
_0811F814: .4byte 0x030046A8
_0811F818: .4byte 0x030046AC
_0811F81C:
	ldr r0, _0811F83C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0811F82A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _0811F840
	adds r0, #4
	b _0811F84C
	.align 2, 0
_0811F83C: .4byte 0x030046A4
_0811F840:
	ldr r0, _0811F860 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0811F84C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0811F864
	cmp r2, #2
	beq _0811F868
	b _0811F86C
	.align 2, 0
_0811F860: .4byte 0x030046A4
_0811F864:
	ldrb r0, [r5, #4]
	b _0811F86A
_0811F868:
	ldrb r0, [r5]
_0811F86A:
	subs r1, r1, r0
_0811F86C:
	strh r1, [r5, #2]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r2, r7, r5
	ldr r1, [r2]
	movs r0, #1
	strh r0, [r1, #6]
	ldr r6, _0811F89C @ =0x000004A4
	adds r0, r7, r6
	ldr r4, [r0]
	ldr r5, [r2]
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	adds r2, r5, #0
	bl Map_IsPosInAgentIsland
	cmp r0, #0
	bne _0811F8A4
	ldr r0, _0811F8A0 @ =0xFFFFFDFF
	mov r2, sl
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	b _0811F8CE
	.align 2, 0
_0811F89C: .4byte 0x000004A4
_0811F8A0: .4byte 0xFFFFFDFF
_0811F8A4:
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	adds r2, r5, #0
	bl Map_TryFindNavRoute
	cmp r0, #0
	beq _0811F8C4
	cmp r0, #2
	beq _0811F8C0
	adds r0, r7, #0
	adds r0, #0x10
	movs r1, #8
	bl ClearMemory
_0811F8C0:
	movs r0, #1
	b _0811F8D0
_0811F8C4:
	ldr r0, _0811F8E4 @ =0xFFFFFDFF
	mov r3, sl
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
_0811F8CE:
	movs r0, #0
_0811F8D0:
	cmp r0, #0
	bne _0811F8F6
	ldr r4, _0811F8E8 @ =0x000005C4
	adds r0, r7, r4
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	b _0811F8F6
	.align 2, 0
_0811F8E4: .4byte 0xFFFFFDFF
_0811F8E8: .4byte 0x000005C4

_0811F8EC:
	ldr r5, _0811F908 @ =0x00000484
	adds r1, r7, r5
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0811F8F6:
	add sp, #0x68
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0811F908: .4byte 0x00000484
