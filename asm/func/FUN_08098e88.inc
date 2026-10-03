	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r3, #0
	ldr r0, _08098ED4 @ =0x030046A0
	mov ip, r0
	mov r8, ip
	ldr r1, _08098ED8 @ =0x00004008
	adds r4, r5, r1
	movs r6, #0
_08098E9E:
	mov r2, r8
	ldr r0, [r2]
	lsls r1, r3, #1
	adds r1, r1, r0
	adds r2, r4, r3
	ldrh r0, [r1, #0x18]
	ldrb r7, [r2]
	adds r0, r0, r7
	strh r0, [r1, #0x18]
	strb r6, [r2]
	adds r3, #1
	cmp r3, #3
	ble _08098E9E
	mov r1, ip
	ldr r0, [r1]
	adds r0, #0x42
	movs r2, #0x80
	lsls r2, r2, #7
	adds r1, r5, r2
	ldrh r1, [r1]
	strh r1, [r0]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098ED4: .4byte 0x030046A0
_08098ED8: .4byte 0x00004008
