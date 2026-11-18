	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x18]
	ldrh r0, [r0, #0x2c]
	movs r1, #0x84
	lsls r1, r1, #3
	adds r2, r5, r1
	strh r0, [r2]
	ldr r0, [r5, #0x18]
	ldrh r0, [r0, #0x2e]
	adds r1, #2
	adds r3, r5, r1
	strh r0, [r3]
	ldr r0, [r5, #0x18]
	ldrh r0, [r0, #0x30]
	adds r1, #2
	adds r4, r5, r1
	strh r0, [r4]
	ldr r0, _081964B0 @ =0x00000AFC
	adds r1, r5, r0
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r1, #0x85
	lsls r1, r1, #3
	adds r2, r5, r1
	strh r0, [r2]
	ldr r0, _081964B4 @ =0x00000AFE
	adds r1, r5, r0
	ldrh r0, [r3]
	ldrh r1, [r1]
	subs r0, r0, r1
	ldr r3, _081964B8 @ =0x0000042A
	adds r1, r5, r3
	strh r0, [r1]
	movs r0, #0xb0
	lsls r0, r0, #4
	adds r1, r5, r0
	ldrh r0, [r4]
	ldrh r1, [r1]
	subs r0, r0, r1
	adds r3, #2
	adds r1, r5, r3
	strh r0, [r1]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	ldr r3, _081964BC @ =0x00000449
	adds r1, r5, r3
	strb r0, [r1]
	ldr r3, _081964C0 @ =gSineTable
	ldrb r2, [r1]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r2, r2, #1
	adds r2, r2, r3
	movs r3, #0
	ldrsh r1, [r2, r3]
	cmp r0, #0
	blt _081964C4
	asrs r0, r0, #0xa
	b _081964CA
	.align 2, 0
_081964B0: .4byte 0x00000AFC
_081964B4: .4byte 0x00000AFE
_081964B8: .4byte 0x0000042A
_081964BC: .4byte 0x00000449
_081964C0: .4byte gSineTable
_081964C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_081964CA:
	strh r0, [r5, #0x1c]
	cmp r1, #0
	blt _081964D4
	asrs r0, r1, #0xa
	b _081964DA
_081964D4:
	rsbs r0, r1, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_081964DA:
	strh r0, [r5, #0x20]
	ldr r0, _0819650C @ =0x00000AFC
	adds r2, r5, r0
	ldrh r1, [r5, #0x2c]
	ldrh r3, [r5, #0x1c]
	adds r1, r1, r3
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	movs r0, #0xb0
	lsls r0, r0, #4
	adds r2, r5, r0
	ldrh r1, [r5, #0x2c]
	ldrh r3, [r5, #0x20]
	adds r1, r1, r3
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	movs r1, #0x2c
	ldrsh r0, [r5, r1]
	cmp r0, #0
	blt _08196510
	asrs r0, r0, #1
	b _08196516
	.align 2, 0
_0819650C: .4byte 0x00000AFC
_08196510:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08196516:
	strh r0, [r5, #0x2c]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	cmp r0, #0
	blt _08196524
	asrs r0, r0, #1
	b _0819652A
_08196524:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0819652A:
	strh r0, [r5, #0x30]
	ldr r3, _0819656C @ =0x00000C64
	adds r1, r5, r3
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
	cmp r0, #0
	bne _08196566
	movs r0, #0x96
	lsls r0, r0, #1
	str r0, [r1]
	movs r0, #1
	movs r1, #3
	adds r2, r5, #0
	adds r2, #0x4a
	strb r0, [r2]
	adds r2, #1
	strb r1, [r2]
	subs r2, #6
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
	ldr r0, _08196570 @ =0x00000C38
	adds r1, r5, r0
	ldr r0, _08196574 @ =FUN_08197858
	str r0, [r1]
	ldr r2, _08196578 @ =0x00000C44
	adds r1, r5, r2
	ldr r0, _0819657C @ =FUN_081963f0
	str r0, [r1]
_08196566:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0819656C: .4byte 0x00000C64
_08196570: .4byte 0x00000C38
_08196574: .4byte FUN_08197858
_08196578: .4byte 0x00000C44
_0819657C: .4byte FUN_081963f0
