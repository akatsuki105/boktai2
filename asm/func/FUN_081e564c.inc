	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa
	bne _081E56C0
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r5, r3
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E56A8 @ =0x00001514
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r3, #0xde
	lsls r3, r3, #3
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E56AC @ =0x000014B4
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081E56B0 @ =0x00001624
	adds r0, r5, r1
	strb r2, [r0]
	ldr r0, _081E56B4 @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r5, #0x18]
	ldr r3, _081E56B8 @ =0x00001614
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _081E56BC @ =0x00001616
	adds r0, r5, r2
	strb r1, [r0]
	b _081E57E0
	.align 2, 0
_081E56A8: .4byte 0x00001514
_081E56AC: .4byte 0x000014B4
_081E56B0: .4byte 0x00001624
_081E56B4: .4byte FUN_081e653c
_081E56B8: .4byte 0x00001614
_081E56BC: .4byte 0x00001616
_081E56C0:
	ldr r3, _081E5720 @ =0x00001614
	adds r6, r5, r3
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E573C
	ldr r1, _081E5724 @ =0x00001608
	adds r0, r5, r1
	ldr r0, [r0]
	bl TextPanel_Hide
	ldr r2, _081E5728 @ =0x00001514
	adds r1, r5, r2
	ldr r0, [r1]
	movs r4, #1
	orrs r0, r4
	str r0, [r1]
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	movs r0, #0xde
	lsls r0, r0, #3
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	ldr r2, _081E572C @ =0x0000161C
	adds r1, r5, r2
	ldr r0, _081E5730 @ =0x03002CF0
	ldr r0, [r0]
	str r0, [r1]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0xb
	bl FUN_081e4cb4
	ldr r3, _081E5734 @ =0x00001618
	adds r1, r5, r3
	movs r2, #0
	movs r0, #0xb
	strb r0, [r1]
	ldr r1, _081E5738 @ =0x00001622
	adds r0, r5, r1
	strb r4, [r0]
	strb r2, [r6]
	b _081E57E0
	.align 2, 0
_081E5720: .4byte 0x00001614
_081E5724: .4byte 0x00001608
_081E5728: .4byte 0x00001514
_081E572C: .4byte 0x0000161C
_081E5730: .4byte 0x03002CF0
_081E5734: .4byte 0x00001618
_081E5738: .4byte 0x00001622
_081E573C:
	adds r0, r5, #0
	bl FUN_081e2ee8
	movs r2, #0x80
	lsls r2, r2, #0xc
	ldr r3, _081E5758 @ =0x00001610
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _081E575C
	movs r0, #1
	b _081E575E
	.align 2, 0
_081E5758: .4byte 0x00001610
_081E575C:
	movs r0, #0
_081E575E:
	cmp r0, #0
	beq _081E577C
	ldr r0, _081E5774 @ =0x000015E2
	adds r1, r5, r0
	ldr r2, _081E5778 @ =0x00001618
	adds r0, r5, r2
	ldrb r2, [r0]
	adds r0, r5, #0
	bl FUN_081e4cb4
	b _081E57E0
	.align 2, 0
_081E5774: .4byte 0x000015E2
_081E5778: .4byte 0x00001618
_081E577C:
	ldr r3, _081E57A0 @ =0x00001622
	adds r4, r5, r3
	ldrb r0, [r4]
	cmp r0, #1
	bne _081E57AC
	ldr r0, _081E57A4 @ =0x000015E2
	adds r1, r5, r0
	adds r0, r5, #0
	movs r2, #0xc
	bl FUN_081e4cb4
	ldr r2, _081E57A8 @ =0x00001618
	adds r1, r5, r2
	movs r0, #0xc
	strb r0, [r1]
	movs r0, #2
	strb r0, [r4]
	b _081E57E0
	.align 2, 0
_081E57A0: .4byte 0x00001622
_081E57A4: .4byte 0x000015E2
_081E57A8: .4byte 0x00001618
_081E57AC:
	movs r1, #0x80
	lsls r1, r1, #0xf
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081E57BC
	movs r0, #1
	b _081E57BE
_081E57BC:
	movs r0, #0
_081E57BE:
	cmp r0, #0
	beq _081E57E0
	bl LinkShopManager_IsBusy
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081E57E0
	ldr r0, _081E57E8 @ =FUN_081e57f4
	movs r2, #0xa
	str r0, [r5, #0x18]
	ldr r3, _081E57EC @ =0x00001614
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E57F0 @ =0x00001616
	adds r0, r5, r1
	strb r2, [r0]
_081E57E0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E57E8: .4byte FUN_081e57f4
_081E57EC: .4byte 0x00001614
_081E57F0: .4byte 0x00001616
