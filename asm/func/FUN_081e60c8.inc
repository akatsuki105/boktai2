	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E60FC @ =0x00001614
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _081E60E0
	ldr r0, _081E6100 @ =0x00001617
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	strb r0, [r2]
_081E60E0:
	adds r0, r4, #0
	bl FUN_081e2ee8
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E6104 @ =0x00001610
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E6108
	movs r0, #1
	b _081E610A
	.align 2, 0
_081E60FC: .4byte 0x00001614
_081E6100: .4byte 0x00001617
_081E6104: .4byte 0x00001610
_081E6108:
	movs r0, #0
_081E610A:
	cmp r0, #0
	beq _081E6118
	adds r0, r4, #0
	movs r1, #8
	bl FUN_081e4c64
	b _081E6164
_081E6118:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E6128
	movs r0, #1
	b _081E612A
_081E6128:
	movs r0, #0
_081E612A:
	cmp r0, #0
	beq _081E6164
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #8
	bne _081E6164
	bl LinkShopManager_IsBusy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E6164
	ldr r1, _081E616C @ =0x0000160C
	adds r0, r4, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r0, _081E6170 @ =FUN_081e617c
	movs r2, #0x17
	str r0, [r4, #0x18]
	ldr r0, _081E6174 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E6178 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
_081E6164:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E616C: .4byte 0x0000160C
_081E6170: .4byte FUN_081e617c
_081E6174: .4byte 0x00001614
_081E6178: .4byte 0x00001616
