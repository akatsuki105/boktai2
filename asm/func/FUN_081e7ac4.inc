	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _081E7B1C @ =0x00001614
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E7AEA
	ldr r0, _081E7B20 @ =0x0000162A
	adds r1, r5, r0
	movs r4, #0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _081E7B24 @ =0x00001618
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_081e4c64
	strb r4, [r6]
_081E7AEA:
	adds r0, r5, #0
	bl FUN_081e2ee8
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xb
	bne _081E7B30
	ldr r0, _081E7B28 @ =FUN_081e78d0
	movs r2, #0x1a
	str r0, [r5, #0x18]
	ldr r0, _081E7B1C @ =0x00001614
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7B2C @ =0x00001616
	adds r0, r5, r1
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081E7BEA
	.align 2, 0
_081E7B1C: .4byte 0x00001614
_081E7B20: .4byte 0x0000162A
_081E7B24: .4byte 0x00001618
_081E7B28: .4byte FUN_081e78d0
_081E7B2C: .4byte 0x00001616
_081E7B30:
	adds r0, r5, #0
	bl FUN_081e4a60
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E7B4C @ =0x00001610
	adds r1, r5, r0
	ldr r0, [r1]
	ands r0, r2
	adds r4, r1, #0
	cmp r0, #0
	beq _081E7B50
	movs r0, #1
	b _081E7B52
	.align 2, 0
_081E7B4C: .4byte 0x00001610
_081E7B50:
	movs r0, #0
_081E7B52:
	cmp r0, #0
	beq _081E7B68
	ldr r1, _081E7B64 @ =0x00001618
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r5, #0
	bl FUN_081e4c64
	b _081E7BEA
	.align 2, 0
_081E7B64: .4byte 0x00001618
_081E7B68:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0xd
	bne _081E7BEA
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E7B86
	movs r0, #1
	b _081E7B88
_081E7B86:
	movs r0, #0
_081E7B88:
	cmp r0, #0
	beq _081E7BEA
	bl LinkShopManager_IsBusy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E7BEA
	movs r1, #0xb0
	lsls r1, r1, #5
	adds r0, r5, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r1, _081E7BBC @ =0x00001604
	adds r0, r5, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	movs r1, #0x80
	lsls r1, r1, #9
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081E7BC0
	movs r0, #1
	b _081E7BC2
	.align 2, 0
_081E7BBC: .4byte 0x00001604
_081E7BC0:
	movs r0, #0
_081E7BC2:
	cmp r0, #0
	beq _081E7BD0
	ldr r0, _081E7BCC @ =FUN_081e6f28
	movs r2, #3
	b _081E7BD4
	.align 2, 0
_081E7BCC: .4byte FUN_081e6f28
_081E7BD0:
	ldr r0, _081E7BF0 @ =FUN_081e7414
	movs r2, #4
_081E7BD4:
	str r0, [r5, #0x18]
	ldr r0, _081E7BF4 @ =0x00001614
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E7BF8 @ =0x00001616
	adds r0, r5, r1
	strb r2, [r0]
	movs r0, #0xdd
	bl PlaySound_082406e0
_081E7BEA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E7BF0: .4byte FUN_081e7414
_081E7BF4: .4byte 0x00001614
_081E7BF8: .4byte 0x00001616
