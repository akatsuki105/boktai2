	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	ldr r0, _081F63A8 @ =0x000006EA
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081F63C4
	ldr r2, _081F63AC @ =0x000006DC
	adds r1, r5, r2
	movs r4, #0
	str r4, [sp]
	mov r0, sp
	ldr r2, _081F63B0 @ =0x05000002
	bl CpuSet
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r4, [r0]
	strb r4, [r6]
	movs r1, #1
	ldr r2, _081F63B4 @ =0x000006E4
	adds r0, r5, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	ands r0, r1
	cmp r0, #0
	beq _081F63B8
	movs r0, #1
	b _081F63BA
	.align 2, 0
_081F63A8: .4byte 0x000006EA
_081F63AC: .4byte 0x000006DC
_081F63B0: .4byte 0x05000002
_081F63B4: .4byte 0x000006E4
_081F63B8:
	movs r0, #0
_081F63BA:
	cmp r0, #0
	beq _081F63C4
	ldr r0, _081F6440 @ =0x000001A5
	bl PlaySound_082406e0
_081F63C4:
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
	adds r3, r0, #0
	adds r3, #0x1c
	ldr r4, _081F6444 @ =0x000006DC
	adds r2, r5, r4
	ldrh r1, [r2]
	ldrh r4, [r0, #0x1c]
	adds r1, r1, r4
	strh r1, [r0, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r2, [r3, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	ldr r4, _081F6448 @ =0x000006DE
	adds r1, r5, r4
	ldrh r0, [r1]
	subs r0, #0xc
	strh r0, [r1]
	ldr r2, _081F644C @ =0x000061A8
	adds r0, r5, #0
	movs r1, #4
	bl Entity081f73ec_FollowHead
	adds r0, r5, #0
	bl Entity081f73ec_UpdateBuried
	adds r0, r5, #0
	bl Entity081f73ec_UpdateHitbox
	adds r0, r5, #0
	bl Entity081f73ec_UpdateFlash
	adds r0, r5, #0
	bl Entity081f73ec_UpdateBuried
	cmp r0, #0
	bge _081F6438
	ldr r0, _081F6450 @ =0x000006E6
	adds r1, r5, r0
	movs r0, #6
	strb r0, [r1]
	ldr r2, _081F6454 @ =0x000006EA
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_081F6438:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081F6440: .4byte 0x000001A5
_081F6444: .4byte 0x000006DC
_081F6448: .4byte 0x000006DE
_081F644C: .4byte 0x000061A8
_081F6450: .4byte 0x000006E6
_081F6454: .4byte 0x000006EA
