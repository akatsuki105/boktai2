	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _0807A834 @ =0x030046A0
	ldr r2, [r0]
	movs r4, #0x94
	lsls r4, r4, #2
	adds r0, r2, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #5
	beq _0807A82E
	cmp r3, #4
	bgt _0807A82E
	lsls r0, r3, #1
	adds r0, r0, r2
	adds r2, r0, #0
	adds r2, #0x46
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	ldr r1, _0807A838 @ =0x26AB0000
	cmp r0, r1
	ble _0807A82E
	ldr r1, _0807A83C @ =0x000026AC
	adds r0, r1, #0
	strh r0, [r2]
_0807A82E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0807A834: .4byte 0x030046A0
_0807A838: .4byte 0x26AB0000
_0807A83C: .4byte 0x000026AC
