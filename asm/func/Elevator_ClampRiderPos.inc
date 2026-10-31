	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	mov ip, r2
	mov r1, ip
	adds r1, #0xfc
	ldrh r0, [r0]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _081D4440 @ =0xFFFF0000
	adds r1, r3, #0
	ands r1, r4
	orrs r1, r0
	adds r2, #0xfe
	mov r6, r8
	ldrh r0, [r6, #2]
	ldrh r2, [r2]
	subs r0, r0, r2
	lsls r0, r0, #0x10
	ldr r2, _081D4444 @ =0x0000FFFF
	ands r1, r2
	adds r4, r1, #0
	orrs r4, r0
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r6, #4]
	ldrh r1, [r1]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r3, r5
	adds r5, r3, #0
	orrs r5, r0
	mov r0, ip
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #2
	bne _081D442A
	b _081D4530
_081D442A:
	cmp r0, #1
	bne _081D444C
	mov r0, ip
	adds r0, #0xd6
	ldrh r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _081D444C
	ldr r0, _081D4448 @ =0x085AE0D8
	b _081D444E
	.align 2, 0
_081D4440: .4byte 0xFFFF0000
_081D4444: .4byte 0x0000FFFF
_081D4448: .4byte 0x085AE0D8
_081D444C:
	ldr r0, _081D4470 @ =0x085AE0D0
_081D444E:
	ldr r6, [r0]
	ldr r7, [r0, #4]
	lsls r0, r4, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bge _081D4474
	adds r2, r6, #0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmn r1, r0
	bge _081D4492
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r0, r2
	b _081D4486
	.align 2, 0
_081D4470: .4byte 0x085AE0D0
_081D4474:
	adds r2, r6, #0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	ble _081D4492
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r2, r0
_081D4486:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _081D44AC @ =0xFFFF0000
	ands r1, r4
	adds r4, r1, #0
	orrs r4, r0
_081D4492:
	adds r2, r4, #0
	asrs r0, r2, #0x10
	cmp r0, #0
	bge _081D44B0
	asrs r1, r6, #0x10
	cmn r0, r1
	bge _081D44C8
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r0, r1
	b _081D44BE
	.align 2, 0
_081D44AC: .4byte 0xFFFF0000
_081D44B0:
	asrs r1, r6, #0x10
	cmp r0, r1
	ble _081D44C8
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r1, r0
_081D44BE:
	lsls r0, r0, #0x10
	ldr r1, _081D44E4 @ =0x0000FFFF
	ands r2, r1
	adds r4, r2, #0
	orrs r4, r0
_081D44C8:
	lsls r0, r5, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bge _081D44E8
	adds r2, r7, #0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmn r1, r0
	bge _081D4506
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r0, r2
	b _081D44FA
	.align 2, 0
_081D44E4: .4byte 0x0000FFFF
_081D44E8:
	adds r2, r7, #0
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	cmp r1, r0
	ble _081D4506
	mov r0, ip
	adds r0, #0xba
	ldrh r0, [r0]
	subs r0, r2, r0
_081D44FA:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _081D453C @ =0xFFFF0000
	ands r1, r5
	adds r5, r1, #0
	orrs r5, r0
_081D4506:
	mov r1, ip
	adds r1, #0xfc
	adds r0, r4, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r1, r8
	strh r0, [r1]
	mov r1, ip
	adds r1, #0xfe
	asrs r0, r4, #0x10
	ldrh r1, [r1]
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2, #2]
	movs r1, #0x80
	lsls r1, r1, #1
	add r1, ip
	adds r0, r5, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #4]
_081D4530:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081D453C: .4byte 0xFFFF0000
