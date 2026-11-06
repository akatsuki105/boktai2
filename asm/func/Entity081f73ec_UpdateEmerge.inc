	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r1, #0
	ldr r0, _081F7188 @ =0x000006EA
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081F713E
	movs r4, #0
	strb r4, [r6]
	ldr r0, _081F718C @ =0x000006DC
	adds r1, r5, r0
	str r4, [sp]
	mov r0, sp
	ldr r2, _081F7190 @ =0x05000002
	bl CpuSet
	ldr r0, _081F7194 @ =0x000006DE
	adds r1, r5, r0
	movs r0, #0x7c
	strh r0, [r1]
	movs r1, #0xdd
	lsls r1, r1, #3
	adds r0, r5, r1
	strh r4, [r0]
_081F713E:
	ldr r0, _081F7194 @ =0x000006DE
	adds r4, r5, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	ble _081F7198
	movs r6, #0xdb
	lsls r6, r6, #3
	adds r0, r5, r6
	ldrb r1, [r0]
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r5, r0
	adds r3, r0, #0
	adds r3, #0x1c
	ldr r1, _081F718C @ =0x000006DC
	adds r2, r5, r1
	ldrh r1, [r2]
	ldrh r6, [r0, #0x1c]
	adds r1, r1, r6
	strh r1, [r0, #0x1c]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r6, [r3, #4]
	adds r0, r0, r6
	strh r0, [r3, #4]
	ldrh r0, [r4]
	subs r0, #8
	strh r0, [r4]
	b _081F71A4
	.align 2, 0
_081F7188: .4byte 0x000006EA
_081F718C: .4byte 0x000006DC
_081F7190: .4byte 0x05000002
_081F7194: .4byte 0x000006DE
_081F7198:
	ldr r1, _081F71CC @ =0x000006E6
	adds r0, r5, r1
	movs r1, #3
	strb r1, [r0]
	movs r0, #1
	strb r0, [r6]
_081F71A4:
	movs r2, #0xfa
	lsls r2, r2, #7
	adds r0, r5, #0
	movs r1, #4
	bl Entity081f73ec_FollowHead
	adds r0, r5, #0
	bl Entity081f73ec_UpdateBuried
	adds r0, r5, #0
	bl Entity081f73ec_UpdateHitbox
	adds r0, r5, #0
	bl Entity081f73ec_UpdateFlash
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081F71CC: .4byte 0x000006E6
