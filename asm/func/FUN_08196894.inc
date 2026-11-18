	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0x85
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r0, _08196954 @ =0x0000044C
	adds r5, r4, r0
	ldrh r0, [r5]
	muls r0, r1, r0
	movs r1, #0x10
	bl Div
	movs r2, #0x86
	lsls r2, r2, #3
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	ldr r0, _08196958 @ =0x00000AFC
	adds r7, r4, r0
	strh r1, [r7]
	ldr r1, _0819695C @ =0x0000042A
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r5]
	muls r0, r1, r0
	movs r1, #0x10
	bl Div
	ldr r2, _08196960 @ =0x00000432
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	ldr r0, _08196964 @ =0x00000AFE
	adds r6, r4, r0
	strh r1, [r6]
	ldr r1, _08196968 @ =0x0000042C
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrh r0, [r5]
	muls r0, r1, r0
	movs r1, #0x10
	bl Div
	ldr r2, _0819696C @ =0x00000434
	adds r1, r4, r2
	ldrh r1, [r1]
	adds r1, r1, r0
	movs r0, #0xb0
	lsls r0, r0, #4
	adds r2, r4, r0
	strh r1, [r2]
	ldrh r0, [r5]
	adds r1, r0, #1
	strh r1, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x10
	bls _0819694C
	movs r0, #0
	strh r0, [r5]
	movs r1, #0x84
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r7]
	adds r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r6]
	adds r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r2]
	ldr r5, _08196970 @ =FUN_08196978
	movs r3, #1
	adds r1, r4, #0
	adds r1, #0x60
	adds r2, r4, #0
	adds r2, #0xe4
_0819693A:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x2c
	cmp r1, r2
	ble _0819693A
	ldr r2, _08196974 @ =0x00000C48
	adds r0, r4, r2
	str r5, [r0]
_0819694C:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08196954: .4byte 0x0000044C
_08196958: .4byte 0x00000AFC
_0819695C: .4byte 0x0000042A
_08196960: .4byte 0x00000432
_08196964: .4byte 0x00000AFE
_08196968: .4byte 0x0000042C
_0819696C: .4byte 0x00000434
_08196970: .4byte FUN_08196978
_08196974: .4byte 0x00000C48
