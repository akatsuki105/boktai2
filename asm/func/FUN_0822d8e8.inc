	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	bl FUN_0822d00c
	mov ip, r0
	ldr r0, _0822D980 @ =0x03004468
	mov r1, ip
	str r1, [r0]
	movs r6, #0
	movs r2, #0xf8
	lsls r2, r2, #2
	mov sb, r2
	movs r0, #0xf8
	lsls r0, r0, #7
	mov r8, r0
_0822D90A:
	lsls r1, r6, #5
	ldr r0, _0822D984 @ =0x03004250
	adds r5, r1, r0
	mov r2, ip
	adds r4, r2, r1
	movs r7, #0xf
_0822D916:
	ldrh r3, [r5]
	movs r2, #0x1f
	ands r2, r3
	mov r1, sb
	ands r1, r3
	lsrs r1, r1, #5
	mov r0, r8
	ands r0, r3
	lsrs r0, r0, #0xa
	adds r2, r2, r1
	adds r2, r2, r0
	asrs r1, r2, #2
	asrs r0, r2, #4
	adds r1, r1, r0
	asrs r0, r2, #6
	adds r2, r1, r0
	lsls r0, r2, #5
	orrs r0, r2
	lsls r1, r2, #0xa
	orrs r0, r1
	strh r0, [r4]
	adds r5, #2
	adds r4, #2
	subs r7, #1
	cmp r7, #0
	bge _0822D916
	adds r6, #1
	cmp r6, #0xc
	ble _0822D90A
	ldr r1, _0822D984 @ =0x03004250
	movs r0, #0xd0
	lsls r0, r0, #1
	mov r2, ip
	adds r4, r2, r0
	adds r5, r1, r0
	movs r6, #2
_0822D95E:
	adds r0, r5, #0
	adds r1, r4, #0
	ldr r2, _0822D988 @ =0x04000008
	bl CpuSet
	adds r4, #0x20
	adds r5, #0x20
	subs r6, #1
	cmp r6, #0
	bge _0822D95E
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822D980: .4byte 0x03004468
_0822D984: .4byte 0x03004250
_0822D988: .4byte 0x04000008
