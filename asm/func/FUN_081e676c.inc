	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _081E67A0 @ =0x00001614
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _081E6784
	ldr r0, _081E67A4 @ =0x00001617
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	strb r0, [r2]
_081E6784:
	adds r0, r4, #0
	bl FUN_081e2ee8
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r0, _081E67A8 @ =0x00001610
	adds r1, r4, r0
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E67AC
	movs r0, #1
	b _081E67AE
	.align 2, 0
_081E67A0: .4byte 0x00001614
_081E67A4: .4byte 0x00001617
_081E67A8: .4byte 0x00001610
_081E67AC:
	movs r0, #0
_081E67AE:
	cmp r0, #0
	beq _081E67BC
	adds r0, r4, #0
	movs r1, #6
	bl FUN_081e4c64
	b _081E680A
_081E67BC:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E67CC
	movs r0, #1
	b _081E67CE
_081E67CC:
	movs r0, #0
_081E67CE:
	cmp r0, #0
	beq _081E680A
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #6
	bne _081E680A
	bl LinkShopManager_IsBusy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E680A
	ldr r1, _081E6800 @ =0x00001624
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081E6804
	cmp r0, #1
	bne _081E680A
	adds r0, r4, #0
	bl FUN_081e4de0
	b _081E680A
	.align 2, 0
_081E6800: .4byte 0x00001624
_081E6804:
	adds r0, r4, #0
	bl FUN_081e4edc
_081E680A:
	pop {r4}
	pop {r0}
	bx r0
