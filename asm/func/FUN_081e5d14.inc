	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081E5D5C @ =0x00001614
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E5D3E
	movs r1, #0x9f
	lsls r1, r1, #4
	adds r2, r4, r1
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	ldr r1, _081E5D60 @ =0x0000160C
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	movs r0, #0
	strb r0, [r5]
_081E5D3E:
	adds r0, r4, #0
	bl FUN_081e2ee8
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E5D64 @ =0x00001610
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r5, r1, #0
	cmp r0, #0
	beq _081E5D68
	movs r0, #1
	b _081E5D6A
	.align 2, 0
_081E5D5C: .4byte 0x00001614
_081E5D60: .4byte 0x0000160C
_081E5D64: .4byte 0x00001610
_081E5D68:
	movs r0, #0
_081E5D6A:
	cmp r0, #0
	beq _081E5D80
	ldr r1, _081E5D7C @ =0x00001618
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_081e4c64
	b _081E5DB4
	.align 2, 0
_081E5D7C: .4byte 0x00001618
_081E5D80:
	bl LinkShopManager_IsBusy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E5DB4
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _081E5D9A
	movs r0, #1
	b _081E5D9C
_081E5D9A:
	movs r0, #0
_081E5D9C:
	cmp r0, #0
	beq _081E5DB4
	ldr r0, _081E5DBC @ =FUN_081e653c
	movs r2, #0x11
	str r0, [r4, #0x18]
	ldr r0, _081E5DC0 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E5DC4 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
_081E5DB4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E5DBC: .4byte FUN_081e653c
_081E5DC0: .4byte 0x00001614
_081E5DC4: .4byte 0x00001616
