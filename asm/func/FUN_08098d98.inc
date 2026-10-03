	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r4, #0
	ldr r0, _08098E2C @ =0x00004004
	adds r6, r5, r0
	movs r1, #0xcc
	lsls r1, r1, #5
	adds r3, r5, r1
	ldr r7, _08098E30 @ =0x000028EC
	adds r2, r5, r7
	movs r0, #2
	rsbs r0, r0, #0
	mov ip, r0
	ldr r1, _08098E34 @ =0x00000F84
	mov r8, r1
_08098DBA:
	ldr r0, [r2]
	mov r7, ip
	ands r0, r7
	str r0, [r2]
	adds r0, r6, r4
	ldrb r0, [r0]
	subs r0, #0x68
	mov r7, r8
	adds r1, r3, r7
	strh r0, [r1]
	lsls r1, r4, #3
	ldr r7, _08098E38 @ =0x00000F86
	adds r0, r3, r7
	strh r1, [r0]
	adds r3, #0x60
	adds r2, #0x60
	adds r4, #1
	cmp r4, #3
	ble _08098DBA
	movs r4, #0
	ldr r0, _08098E3C @ =0x00004008
	adds r0, r0, r5
	mov r8, r0
	ldr r1, _08098E40 @ =0x00002904
	adds r6, r5, r1
	movs r7, #0xd8
	lsls r7, r7, #5
	adds r3, r5, r7
	ldr r0, _08098E44 @ =0x00002A6C
	adds r2, r5, r0
	movs r5, #2
	rsbs r5, r5, #0
_08098DFA:
	ldr r0, [r2]
	ands r0, r5
	str r0, [r2]
	mov r7, r8
	adds r1, r7, r4
	ldrh r0, [r6]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r2, #0x18]
	lsls r1, r4, #3
	ldr r7, _08098E38 @ =0x00000F86
	adds r0, r3, r7
	strh r1, [r0]
	adds r6, #0x60
	adds r3, #0x60
	adds r2, #0x60
	adds r4, #1
	cmp r4, #3
	ble _08098DFA
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08098E2C: .4byte 0x00004004
_08098E30: .4byte 0x000028EC
_08098E34: .4byte 0x00000F84
_08098E38: .4byte 0x00000F86
_08098E3C: .4byte 0x00004008
_08098E40: .4byte 0x00002904
_08098E44: .4byte 0x00002A6C
