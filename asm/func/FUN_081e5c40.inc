	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081E5C88 @ =0x00001614
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E5C6A
	movs r1, #0x9f
	lsls r1, r1, #4
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _081E5C8C @ =0x0000160C
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	movs r0, #0
	strb r0, [r5]
_081E5C6A:
	adds r0, r4, #0
	bl FUN_081e2ee8
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E5C90 @ =0x00001610
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081E5C94
	movs r0, #1
	b _081E5C96
	.align 2, 0
_081E5C88: .4byte 0x00001614
_081E5C8C: .4byte 0x0000160C
_081E5C90: .4byte 0x00001610
_081E5C94:
	movs r0, #0
_081E5C96:
	cmp r0, #0
	beq _081E5CA4
	adds r0, r4, #0
	movs r1, #3
	bl FUN_081e4c64
	b _081E5CFC
_081E5CA4:
	bl LinkShopManager_IsBusy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E5CFC
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081E5CBE
	movs r0, #1
	b _081E5CC0
_081E5CBE:
	movs r0, #0
_081E5CC0:
	cmp r0, #0
	beq _081E5CFC
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #3
	bne _081E5CDC
	ldr r0, _081E5CD8 @ =FUN_081e5dc8
	movs r2, #0xe
	b _081E5CEC
	.align 2, 0
_081E5CD8: .4byte FUN_081e5dc8
_081E5CDC:
	cmp r0, #9
	bne _081E5CFC
	ldr r0, _081E5D04 @ =0x00001624
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r0, _081E5D08 @ =FUN_081e653c
	movs r2, #0x11
_081E5CEC:
	str r0, [r4, #0x18]
	ldr r0, _081E5D0C @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E5D10 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
_081E5CFC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E5D04: .4byte 0x00001624
_081E5D08: .4byte FUN_081e653c
_081E5D0C: .4byte 0x00001614
_081E5D10: .4byte 0x00001616
