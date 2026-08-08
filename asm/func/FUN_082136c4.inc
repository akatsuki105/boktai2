	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x59
	bl prepare_08231510
	cmp r0, #0
	beq _082136D8
	bl fetch_082316e4
	str r0, [r4, #0x40]
_082136D8:
	movs r0, #0x44
	movs r1, #0
	bl FUN_0823174c
	adds r5, r0, #0
	movs r0, #0x4b
	bl prepare_08231510
	cmp r0, #0
	beq _08213700
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x90
	strh r0, [r1]
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x92
	strh r0, [r1]
_08213700:
	movs r0, #0x6b
	bl prepare_08231510
	cmp r0, #0
	beq _08213728
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x70
	strh r0, [r1]
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x72
	strh r0, [r1]
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x74
	strh r0, [r1]
_08213728:
	movs r0, #0x6a
	bl prepare_08231510
	cmp r0, #0
	beq _08213750
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x76
	strh r0, [r1]
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x78
	strh r0, [r1]
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x7a
	strh r0, [r1]
_08213750:
	movs r0, #0x77
	bl prepare_08231510
	cmp r0, #0
	beq _08213778
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x7c
	strh r0, [r1]
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x7e
	strh r0, [r1]
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x80
	strh r0, [r1]
_08213778:
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _082137A0
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x82
	strh r0, [r1]
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x84
	strh r0, [r1]
	bl fetch_082316e4
	adds r1, r4, #0
	adds r1, #0x86
	strh r0, [r1]
_082137A0:
	movs r0, #0x67
	bl prepare_08231510
	cmp r0, #0
	beq _082137B0
	bl fetch_082316e4
	str r0, [r4, #0x48]
_082137B0:
	movs r0, #0x6f
	bl prepare_08231510
	cmp r0, #0
	beq _082137C0
	bl fetch_082316e4
	str r0, [r4, #0x4c]
_082137C0:
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _082137D0
	bl fetch_082316e4
	str r0, [r4, #0x50]
_082137D0:
	movs r0, #0x73
	bl prepare_08231510
	cmp r0, #0
	beq _082137E0
	bl fetch_082316e4
	str r0, [r4, #0x54]
_082137E0:
	movs r0, #0x64
	bl prepare_08231510
	cmp r0, #0
	beq _082137F0
	bl fetch_082316e4
	str r0, [r4, #0x58]
_082137F0:
	cmp r5, #0
	beq _082137FC
	movs r0, #0x80
	lsls r0, r0, #0x15
	str r0, [r4, #0x44]
	b _082137FE
_082137FC:
	str r5, [r4, #0x44]
_082137FE:
	movs r0, #0
	str r0, [r4, #0x5c]
	str r0, [r4, #0x60]
	str r0, [r4, #0x64]
	str r0, [r4, #0x68]
	subs r0, #1
	str r0, [r4, #0x6c]
	adds r0, r4, #0
	bl FUN_082135f4
	ldr r0, [r4, #0x40]
	subs r0, #1
	cmp r0, #1
	bls _08213826
	movs r1, #0x80
	lsls r1, r1, #0x15
	ldr r0, [r4, #0x44]
	ands r0, r1
	cmp r0, #0
	beq _08213830
_08213826:
	adds r0, r4, #0
	movs r1, #3
	bl FUN_08213630
	b _08213838
_08213830:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08213630
_08213838:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
