	push {r4, r5, r6, lr}
	sub sp, #0x28
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _0823AF2C @ =0xFFFF0000
	ldr r1, [sp, #0x20]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x20]
	add r0, sp, #0x20
	mov r1, sp
	str r1, [r0, #4]
	mov r4, sp
	movs r5, #0
	adds r6, r0, #0
	b _0823AF42
	.align 2, 0
_0823AF2C: .4byte 0xFFFF0000
_0823AF30:
	bl fetch_082316e4
	strh r0, [r4]
	adds r4, #2
	lsls r0, r5, #0x10
	movs r1, #0x80
	lsls r1, r1, #9
	adds r0, r0, r1
	lsrs r5, r0, #0x10
_0823AF42:
	bl FUN_082316bc
	cmp r0, #0
	bne _0823AF30
	lsls r2, r5, #0x18
	ldr r1, _0823AF68 @ =0x00FFFFFF
	ldr r0, [sp, #0x20]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x20]
	adds r0, r6, #0
	bl FUN_08230eec
	movs r0, #0
	add sp, #0x28
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0823AF68: .4byte 0x00FFFFFF
