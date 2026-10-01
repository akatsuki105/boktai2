	push {r4, r5, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldr r1, _0809E648 @ =0x030047A4
	ldr r2, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r2, r0
	cmp r2, #0
	beq _0809E64C
	movs r0, #0
	b _0809E666
	.align 2, 0
_0809E648: .4byte 0x030047A4
_0809E64C:
	ldr r0, _0809E658 @ =0x030044E0
	ldrh r0, [r0]
	cmp r0, #0
	beq _0809E65C
	strh r2, [r4, #0x20]
	b _0809E668
	.align 2, 0
_0809E658: .4byte 0x030044E0
_0809E65C:
	ldrh r2, [r4, #0x20]
	ldr r0, _0809E6A0 @ =0x00000383
	cmp r2, r0
	bhi _0809E668
	adds r0, r2, #1
_0809E666:
	strh r0, [r4, #0x20]
_0809E668:
	ldr r0, [r1]
	movs r1, #0xc0
	lsls r1, r1, #2
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #2
	cmp r0, r1
	beq _0809E722
	movs r1, #4
	ldr r0, _0809E6A4 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0809E722
	ldr r0, [r4, #0x18]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r1, r0, r2
	ldrb r1, [r1]
	adds r5, r0, #0
	cmp r1, #5
	bne _0809E6C0
	cmp r3, #2
	bne _0809E6A8
	ldrh r0, [r4, #0x1e]
	adds r0, #0x28
	b _0809E6FC
	.align 2, 0
_0809E6A0: .4byte 0x00000383
_0809E6A4: .4byte 0x03002BC0
_0809E6A8:
	cmp r3, #0
	bne _0809E6FE
	ldrh r1, [r4, #0x20]
	ldr r0, _0809E6BC @ =0x00000383
	cmp r1, r0
	bhi _0809E6FE
	ldrh r0, [r4, #0x1e]
	adds r0, #5
	b _0809E6FC
	.align 2, 0
_0809E6BC: .4byte 0x00000383
_0809E6C0:
	cmp r3, #2
	bne _0809E6E0
	ldr r0, _0809E6D8 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0809E6DC @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #3
	ldrh r1, [r4, #0x1e]
	adds r0, r0, r1
	b _0809E6FC
	.align 2, 0
_0809E6D8: .4byte 0x030046A0
_0809E6DC: .4byte 0x00000942
_0809E6E0:
	cmp r3, #1
	bne _0809E6FE
	ldrh r1, [r4, #0x20]
	ldr r0, _0809E728 @ =0x00000383
	cmp r1, r0
	bhi _0809E6FE
	ldr r0, _0809E72C @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0809E730 @ =0x00000942
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrh r2, [r4, #0x1e]
	adds r0, r0, r2
_0809E6FC:
	strh r0, [r4, #0x1e]
_0809E6FE:
	movs r1, #0
	ldrh r3, [r4, #0x1e]
	cmp r3, #0x77
	bls _0809E718
_0809E706:
	adds r2, r3, #0
	subs r2, #0x78
	adds r1, #1
	adds r3, r2, #0
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bhi _0809E706
	strh r2, [r4, #0x1e]
_0809E718:
	cmp r1, #0
	ble _0809E722
	adds r0, r5, #0
	bl FUN_0807aa30
_0809E722:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809E728: .4byte 0x00000383
_0809E72C: .4byte 0x030046A0
_0809E730: .4byte 0x00000942
