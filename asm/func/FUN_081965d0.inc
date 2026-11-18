	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	ldr r0, _081966F8 @ =0x00000CCA
	adds r1, r7, r0
	movs r2, #0x89
	lsls r2, r2, #3
	adds r4, r7, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0xff
	ble _08196600
	movs r0, #0
	strh r0, [r1]
	ldr r0, _081966FC @ =0x00000169
	bl PlaySound_082406e0
_08196600:
	ldr r0, _08196700 @ =0x00000AE6
	adds r1, r7, r0
	ldrb r0, [r4]
	ldrb r2, [r1]
	adds r0, r0, r2
	strb r0, [r1]
	ldr r3, _08196704 @ =0x00000CEC
	adds r0, r7, r3
	ldr r0, [r0]
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0819662A
	ldrb r0, [r4]
	adds r0, #1
	strb r0, [r4]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #7
	ble _0819662A
	strb r1, [r4]
_0819662A:
	ldr r0, _08196708 @ =0x0000044C
	adds r0, r0, r7
	mov sb, r0
	ldrh r0, [r0]
	adds r0, #1
	mov r1, sb
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x96
	bls _081966EC
	ldr r2, _0819670C @ =0x00000AFC
	adds r5, r7, r2
	movs r3, #0
	ldrsh r0, [r5, r3]
	ldr r2, [r7, #0x18]
	movs r3, #0x2c
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r1, #0xb0
	lsls r1, r1, #4
	adds r6, r7, r1
	movs r3, #0
	ldrsh r1, [r6, r3]
	movs r3, #0x30
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	movs r1, #0x20
	subs r1, r1, r0
	ldr r2, _08196710 @ =0x00000449
	adds r0, r7, r2
	strb r1, [r0]
	ldrh r1, [r5]
	movs r3, #0x86
	lsls r3, r3, #3
	adds r0, r7, r3
	strh r1, [r0]
	ldr r0, _08196714 @ =0x00000AFE
	adds r0, r0, r7
	mov r8, r0
	ldrh r1, [r0]
	subs r2, #0x17
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r1, [r6]
	adds r3, #4
	adds r0, r7, r3
	strh r1, [r0]
	ldr r0, [r7, #0x18]
	ldrh r0, [r0, #0x2c]
	movs r1, #0x84
	lsls r1, r1, #3
	adds r2, r7, r1
	strh r0, [r2]
	ldr r1, [r7, #0x18]
	movs r3, #0xaf
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r1, [r1, #0x2e]
	adds r0, r0, r1
	ldr r1, _08196718 @ =0x00000422
	adds r3, r7, r1
	strh r0, [r3]
	ldr r0, [r7, #0x18]
	ldrh r0, [r0, #0x30]
	adds r1, #2
	adds r4, r7, r1
	strh r0, [r4]
	ldrh r0, [r2]
	ldrh r1, [r5]
	subs r0, r0, r1
	movs r2, #0x85
	lsls r2, r2, #3
	adds r1, r7, r2
	strh r0, [r1]
	ldrh r0, [r3]
	mov r3, r8
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	ldrh r0, [r4]
	ldrh r1, [r6]
	subs r0, r0, r1
	ldr r3, _0819671C @ =0x0000042C
	adds r1, r7, r3
	strh r0, [r1]
	movs r0, #0
	mov r1, sb
	strh r0, [r1]
	ldr r2, _08196720 @ =0x00000C48
	adds r1, r7, r2
	ldr r0, _08196724 @ =FUN_08196728
	str r0, [r1]
_081966EC:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081966F8: .4byte 0x00000CCA
_081966FC: .4byte 0x00000169
_08196700: .4byte 0x00000AE6
_08196704: .4byte 0x00000CEC
_08196708: .4byte 0x0000044C
_0819670C: .4byte 0x00000AFC
_08196710: .4byte 0x00000449
_08196714: .4byte 0x00000AFE
_08196718: .4byte 0x00000422
_0819671C: .4byte 0x0000042C
_08196720: .4byte 0x00000C48
_08196724: .4byte FUN_08196728
