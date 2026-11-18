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
	ldr r0, _08196CBC @ =0x00000AFC
	adds r1, r5, r0
	ldrh r0, [r2]
	ldrh r1, [r1]
	subs r0, r0, r1
	movs r1, #0x85
	lsls r1, r1, #3
	adds r2, r5, r1
	strh r0, [r2]
	ldr r0, _08196CC0 @ =0x00000AFE
	adds r1, r5, r0
	ldrh r0, [r3]
	ldrh r1, [r1]
	subs r0, r0, r1
	ldr r3, _08196CC4 @ =0x0000042A
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
	ldr r3, _08196CC8 @ =0x00000449
	adds r1, r5, r3
	strb r0, [r1]
	ldr r3, _08196CCC @ =gSineTable
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
	blt _08196CD0
	asrs r0, r0, #0xa
	b _08196CD6
	.align 2, 0
_08196CBC: .4byte 0x00000AFC
_08196CC0: .4byte 0x00000AFE
_08196CC4: .4byte 0x0000042A
_08196CC8: .4byte 0x00000449
_08196CCC: .4byte gSineTable
_08196CD0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_08196CD6:
	strh r0, [r5, #0x1c]
	cmp r1, #0
	blt _08196CE0
	asrs r0, r1, #0xa
	b _08196CE6
_08196CE0:
	rsbs r0, r1, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_08196CE6:
	strh r0, [r5, #0x20]
	ldr r0, _08196D30 @ =0x00000AFC
	adds r1, r5, r0
	ldrh r0, [r5, #0x1c]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r3, #0xb0
	lsls r3, r3, #4
	adds r1, r5, r3
	ldrh r0, [r5, #0x20]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _08196D34 @ =0x00000CEC
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _08196D28
	movs r0, #0x8a
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	cmp r0, #0x50
	bne _08196D28
	ldr r2, _08196D38 @ =0x00000C4C
	adds r1, r5, r2
	ldr r0, _08196D3C @ =FUN_08196d40
	str r0, [r1]
_08196D28:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08196D30: .4byte 0x00000AFC
_08196D34: .4byte 0x00000CEC
_08196D38: .4byte 0x00000C4C
_08196D3C: .4byte FUN_08196d40
