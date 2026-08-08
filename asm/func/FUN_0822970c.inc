	push {r4, r5, lr}
	ldr r0, _08229794 @ =0x03000248
	ldr r4, [r0]
	cmp r4, #0
	bne _08229720
	ldr r0, _08229798 @ =0x0000BB34
	movs r1, #0
	bl FUN_08229c6c
	adds r4, r0, #0
_08229720:
	ldr r0, _0822979C @ =0x00000D9C
	adds r5, r4, r0
	ldr r1, _082297A0 @ =0x00000DC8
	adds r0, r4, r1
	ldr r1, _082297A4 @ =0x00000117
	bl FUN_0822b20c
	ldr r2, _082297A8 @ =0x00000DA3
	adds r0, r4, r2
	movs r1, #0
	strb r1, [r0]
	ldr r3, _082297AC @ =0x00000F28
	adds r0, r4, r3
	strb r1, [r0]
	bl fetch_082316e4
	ldr r2, _082297B0 @ =0x00000F46
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0x72
	movs r1, #0
	bl FUN_0823174c
	ldr r3, _082297B4 @ =0x00000F29
	adds r1, r4, r3
	strb r0, [r1]
	movs r0, #0x41
	movs r1, #0
	bl FUN_0823174c
	ldr r2, _082297B8 @ =0x00000F26
	adds r1, r4, r2
	strb r0, [r1]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _082297C4
	bl fetch_082316e4
	ldr r3, _082297BC @ =0x00000E9C
	adds r1, r4, r3
	strh r0, [r1]
	strh r0, [r5, #0x1c]
	bl fetch_082316e4
	ldr r2, _082297C0 @ =0x00000E9E
	adds r1, r4, r2
	strh r0, [r1]
	strh r0, [r5, #0x1e]
	bl fetch_082316e4
	movs r3, #0xea
	lsls r3, r3, #4
	adds r1, r4, r3
	strh r0, [r1]
	b _082297EC
	.align 2, 0
_08229794: .4byte 0x03000248
_08229798: .4byte 0x0000BB34
_0822979C: .4byte 0x00000D9C
_082297A0: .4byte 0x00000DC8
_082297A4: .4byte 0x00000117
_082297A8: .4byte 0x00000DA3
_082297AC: .4byte 0x00000F28
_082297B0: .4byte 0x00000F46
_082297B4: .4byte 0x00000F29
_082297B8: .4byte 0x00000F26
_082297BC: .4byte 0x00000E9C
_082297C0: .4byte 0x00000E9E
_082297C4:
	ldr r2, [r4, #0x18]
	ldrh r1, [r2, #0x2c]
	ldr r3, _08229828 @ =0x00000E9C
	adds r0, r4, r3
	strh r1, [r0]
	ldrh r0, [r2, #0x2c]
	strh r0, [r5, #0x1c]
	ldr r2, [r4, #0x18]
	ldrh r1, [r2, #0x2e]
	adds r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldrh r0, [r2, #0x2e]
	strh r0, [r5, #0x1e]
	ldr r2, [r4, #0x18]
	ldrh r1, [r2, #0x30]
	adds r3, #2
	adds r0, r4, r3
	strh r1, [r0]
	ldrh r0, [r2, #0x30]
_082297EC:
	strh r0, [r5, #0x20]
	movs r0, #0x63
	bl prepare_08231510
	cmp r0, #0
	beq _08229802
	bl fetch_082316e4
	ldr r2, _0822982C @ =0x00000F0C
	adds r1, r4, r2
	str r0, [r1]
_08229802:
	movs r0, #0x73
	movs r1, #0
	bl FUN_0823174c
	ldr r3, _08229830 @ =0x00000F21
	adds r1, r4, r3
	strb r0, [r1]
	ldr r0, _08229834 @ =gClock
	ldrb r0, [r0, #0xe]
	cmp r0, #5
	beq _0822983C
	cmp r0, #0
	beq _0822983C
	cmp r0, #4
	beq _0822983C
	ldr r0, _08229838 @ =0x00000F2B
	adds r1, r4, r0
	movs r0, #1
	b _08229842
	.align 2, 0
_08229828: .4byte 0x00000E9C
_0822982C: .4byte 0x00000F0C
_08229830: .4byte 0x00000F21
_08229834: .4byte gClock
_08229838: .4byte 0x00000F2B
_0822983C:
	ldr r2, _08229870 @ =0x00000F2B
	adds r1, r4, r2
	movs r0, #0
_08229842:
	strb r0, [r1]
	ldr r3, _08229874 @ =0x00000DF4
	adds r0, r4, r3
	bl FUN_080136b4
	ldr r0, _08229878 @ =0x00000D9C
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _0822987C @ =0x00000F21
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bls _08229864
	b _08229A0A
_08229864:
	lsls r0, r0, #2
	ldr r1, _08229880 @ =_08229884
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_08229870: .4byte 0x00000F2B
_08229874: .4byte 0x00000DF4
_08229878: .4byte 0x00000D9C
_0822987C: .4byte 0x00000F21
_08229880: .4byte _08229884
_08229884: @ jump table
	.4byte _0822989C @ case 0
	.4byte _082298D8 @ case 1
	.4byte _0822990C @ case 2
	.4byte _08229940 @ case 3
	.4byte _08229974 @ case 4
	.4byte _082299A8 @ case 5
_0822989C:
	ldr r2, _082298D0 @ =0x00000F16
	adds r3, r4, r2
	ldrb r0, [r3]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _082298D4 @ =0x00000F18
	adds r2, r4, r1
	strh r0, [r2]
	ldrb r1, [r3]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	strb r0, [r3]
	ldrh r1, [r3]
	movs r5, #0xf
	adds r0, r5, #0
	ands r0, r1
	strh r0, [r3]
	ldrh r0, [r2]
	cmp r0, #3
	beq _082298C8
	b _082299FC
_082298C8:
	ldrb r1, [r3]
	adds r0, r5, #0
	b _082299DE
	.align 2, 0
_082298D0: .4byte 0x00000F16
_082298D4: .4byte 0x00000F18
_082298D8:
	ldr r0, _08229904 @ =0x00000F16
	adds r5, r4, r0
	ldrb r0, [r5]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _08229908 @ =0x00000F18
	adds r3, r4, r1
	strh r0, [r3]
	movs r2, #2
	ldrb r1, [r5]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5]
	ldrh r1, [r5]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0x10
	b _082299D0
	.align 2, 0
_08229904: .4byte 0x00000F16
_08229908: .4byte 0x00000F18
_0822990C:
	ldr r0, _08229938 @ =0x00000F16
	adds r5, r4, r0
	ldrb r0, [r5]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _0822993C @ =0x00000F18
	adds r3, r4, r1
	strh r0, [r3]
	movs r2, #2
	ldrb r1, [r5]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5]
	ldrh r1, [r5]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0x20
	b _082299D0
	.align 2, 0
_08229938: .4byte 0x00000F16
_0822993C: .4byte 0x00000F18
_08229940:
	ldr r0, _0822996C @ =0x00000F16
	adds r5, r4, r0
	ldrb r0, [r5]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _08229970 @ =0x00000F18
	adds r3, r4, r1
	strh r0, [r3]
	movs r2, #2
	ldrb r1, [r5]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5]
	ldrh r1, [r5]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0x30
	b _082299D0
	.align 2, 0
_0822996C: .4byte 0x00000F16
_08229970: .4byte 0x00000F18
_08229974:
	ldr r0, _082299A0 @ =0x00000F16
	adds r5, r4, r0
	ldrb r0, [r5]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _082299A4 @ =0x00000F18
	adds r3, r4, r1
	strh r0, [r3]
	movs r2, #2
	ldrb r1, [r5]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5]
	ldrh r1, [r5]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0x50
	b _082299D0
	.align 2, 0
_082299A0: .4byte 0x00000F16
_082299A4: .4byte 0x00000F18
_082299A8:
	ldr r0, _08229A10 @ =0x00000F16
	adds r5, r4, r0
	ldrb r0, [r5]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	ldr r1, _08229A14 @ =0x00000F18
	adds r3, r4, r1
	strh r0, [r3]
	movs r2, #2
	ldrb r1, [r5]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r5]
	ldrh r1, [r5]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	movs r1, #0x60
_082299D0:
	orrs r0, r1
	strh r0, [r5]
	ldrh r0, [r3]
	cmp r0, #3
	bne _082299FC
	ldrb r1, [r5]
	adds r0, r2, #0
_082299DE:
	ands r0, r1
	cmp r0, #3
	bne _082299FC
	ldr r2, _08229A18 @ =0x00000DEC
	adds r0, r4, r2
	ldrh r1, [r0]
	ldr r3, _08229A1C @ =0x00000F42
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _08229A20 @ =0x00000DF2
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _08229A24 @ =0x00000F43
	adds r0, r4, r2
	strb r1, [r0]
_082299FC:
	movs r0, #1
	movs r3, #0xf2
	lsls r3, r3, #4
	adds r2, r4, r3
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_08229A0A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08229A10: .4byte 0x00000F16
_08229A14: .4byte 0x00000F18
_08229A18: .4byte 0x00000DEC
_08229A1C: .4byte 0x00000F42
_08229A20: .4byte 0x00000DF2
_08229A24: .4byte 0x00000F43
