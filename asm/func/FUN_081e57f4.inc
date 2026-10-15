	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081E5824 @ =0x00001614
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E580E
	adds r0, r4, #0
	movs r1, #4
	bl FUN_081e4c64
	movs r0, #0
	strb r0, [r5]
_081E580E:
	movs r2, #0x80
	lsls r2, r2, #0xb
	ldr r3, _081E5828 @ =0x00001610
	adds r1, r4, r3
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E582C
	movs r0, #1
	b _081E582E
	.align 2, 0
_081E5824: .4byte 0x00001614
_081E5828: .4byte 0x00001610
_081E582C:
	movs r0, #0
_081E582E:
	cmp r0, #0
	beq _081E583C
	adds r0, r4, #0
	movs r1, #4
	bl FUN_081e4c64
	b _081E58D6
_081E583C:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0xa
	bne _081E5868
	adds r1, #4
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	ldr r0, _081E5860 @ =FUN_081e653c
	movs r2, #0x11
	str r0, [r4, #0x18]
	ldr r3, _081E5864 @ =0x00001614
	adds r0, r4, r3
	strb r1, [r0]
	b _081E58BA
	.align 2, 0
_081E5860: .4byte FUN_081e653c
_081E5864: .4byte 0x00001614
_081E5868:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E5878
	movs r0, #1
	b _081E587A
_081E5878:
	movs r0, #0
_081E587A:
	cmp r0, #0
	beq _081E58D0
	movs r3, #0xb1
	lsls r3, r3, #5
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #4
	beq _081E58A2
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E589C
	movs r0, #1
	b _081E589E
_081E589C:
	movs r0, #0
_081E589E:
	cmp r0, #0
	beq _081E58D0
_081E58A2:
	bl LinkShopManager_IsBusy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E58D0
	ldr r0, _081E58C4 @ =FUN_081e58dc
	movs r2, #0xc
	str r0, [r4, #0x18]
	ldr r3, _081E58C8 @ =0x00001614
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_081E58BA:
	ldr r1, _081E58CC @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	b _081E58D6
	.align 2, 0
_081E58C4: .4byte FUN_081e58dc
_081E58C8: .4byte 0x00001614
_081E58CC: .4byte 0x00001616
_081E58D0:
	adds r0, r4, #0
	bl FUN_081e2ee8
_081E58D6:
	pop {r4, r5}
	pop {r0}
	bx r0
