	push {r4, lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x44]
	adds r3, r0, #0
	adds r3, #0x48
	ldr r1, _0817901C @ =0x00000546
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r4, #0xc2
	lsls r4, r4, #1
	adds r0, r2, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r1, r0
	ble _08179040
	ldrh r0, [r3, #0xe]
	cmp r0, #0
	bne _08179094
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #0x10
	ldr r2, _08179020 @ =0x00001008
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08179024
	movs r0, #1
	b _08179026
	.align 2, 0
_0817901C: .4byte 0x00000546
_08179020: .4byte 0x00001008
_08179024:
	movs r0, #0
_08179026:
	cmp r0, #0
	beq _0817906A
	ldr r2, _0817903C @ =0x085ADB3C
	ldrh r1, [r3, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r0, r0, #2
	b _08179096
	.align 2, 0
_0817903C: .4byte 0x085ADB3C
_08179040:
	ldrh r0, [r3, #0xe]
	cmp r0, #0
	bne _08179094
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r0, r2, r4
	ldr r0, [r0]
	movs r1, #0x10
	ldr r2, _08179060 @ =0x00001008
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08179064
	movs r0, #1
	b _08179066
	.align 2, 0
_08179060: .4byte 0x00001008
_08179064:
	movs r0, #0
_08179066:
	cmp r0, #0
	beq _08179080
_0817906A:
	ldr r2, _0817907C @ =0x085ADB3C
	ldrh r1, [r3, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r0, r0, #1
	b _08179096
	.align 2, 0
_0817907C: .4byte 0x085ADB3C
_08179080:
	ldr r2, _08179090 @ =0x085ADB3C
	ldrh r1, [r3, #8]
	movs r0, #3
	ands r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	b _08179096
	.align 2, 0
_08179090: .4byte 0x085ADB3C
_08179094:
	movs r0, #0
_08179096:
	pop {r4}
	pop {r1}
	bx r1
