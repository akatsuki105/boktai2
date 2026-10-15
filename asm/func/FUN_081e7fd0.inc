	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081E8014 @ =0x00001614
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081E7FF0
	movs r0, #1
	bl Sound_FadeOutBGM
	ldr r1, _081E8018 @ =0x0000162A
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r5]
_081E7FF0:
	adds r0, r4, #0
	bl FUN_081e2ee8
	ldr r2, _081E8018 @ =0x0000162A
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0x1d
	bhi _081E801C
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xb
	bne _081E8090
	b _081E8036
	.align 2, 0
_081E8014: .4byte 0x00001614
_081E8018: .4byte 0x0000162A
_081E801C:
	ldr r0, _081E8054 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _081E8036
	movs r2, #0xb1
	lsls r2, r2, #5
	adds r0, r4, r2
	ldrh r1, [r0]
	lsls r0, r1, #0x10
	cmp r1, #0xb
	bne _081E8064
_081E8036:
	ldr r0, _081E8058 @ =FUN_081e78d0
	movs r2, #0x1a
	str r0, [r4, #0x18]
	ldr r0, _081E805C @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E8060 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081E8090
	.align 2, 0
_081E8054: .4byte 0x030044E0
_081E8058: .4byte FUN_081e78d0
_081E805C: .4byte 0x00001614
_081E8060: .4byte 0x00001616
_081E8064:
	lsrs r0, r0, #0x10
	cmp r0, #1
	bhi _081E8090
	ldr r2, _081E8098 @ =0x0000162E
	adds r0, r4, r2
	strh r1, [r0]
	bl FUN_08049e5c
	ldr r0, _081E809C @ =0x00001618
	adds r1, r4, r0
	movs r0, #0xd
	strb r0, [r1]
	ldr r0, _081E80A0 @ =FUN_081e7bfc
	movs r2, #0x1d
	str r0, [r4, #0x18]
	ldr r0, _081E80A4 @ =0x00001614
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E80A8 @ =0x00001616
	adds r0, r4, r1
	strb r2, [r0]
_081E8090:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E8098: .4byte 0x0000162E
_081E809C: .4byte 0x00001618
_081E80A0: .4byte FUN_081e7bfc
_081E80A4: .4byte 0x00001614
_081E80A8: .4byte 0x00001616
