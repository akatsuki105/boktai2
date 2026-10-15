	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r1, _081E6B80 @ =0x00001614
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081E6C3A
	movs r2, #0x80
	lsls r2, r2, #0xa
	ldr r3, _081E6B84 @ =0x00001610
	adds r1, r6, r3
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081E6B88
	movs r0, #1
	b _081E6B8A
	.align 2, 0
_081E6B80: .4byte 0x00001614
_081E6B84: .4byte 0x00001610
_081E6B88:
	movs r0, #0
_081E6B8A:
	adds r3, r0, #0
	cmp r3, #0
	bne _081E6C32
	movs r4, #0xea
	lsls r4, r4, #3
	adds r2, r6, r4
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r5, #0xed
	lsls r5, r5, #3
	adds r1, r6, r5
	movs r5, #0
	movs r0, #0x18
	strh r0, [r1]
	ldr r1, _081E6C90 @ =0x0000076A
	adds r0, r6, r1
	strh r3, [r0]
	ldr r2, _081E6C94 @ =0x000015E6
	adds r0, r6, r2
	strb r5, [r0]
	ldr r3, _081E6C98 @ =0x000015E2
	adds r4, r6, r3
	ldrh r1, [r4]
	adds r0, r6, #0
	bl FUN_081e37a0
	ldrh r1, [r4]
	ldr r2, _081E6C9C @ =0x000015E4
	adds r0, r6, r2
	strh r1, [r0]
	ldr r3, _081E6CA0 @ =0x00001619
	adds r0, r6, r3
	strb r5, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r7]
	orrs r0, r1
	str r0, [r7]
	ldrh r1, [r4]
	movs r2, #0
	ldr r0, _081E6CA4 @ =0x000003E7
	cmp r1, r0
	ble _081E6BF0
	ldr r3, _081E6CA8 @ =0xFFFFFC18
_081E6BE8:
	adds r2, #1
	adds r1, r1, r3
	cmp r1, r0
	bgt _081E6BE8
_081E6BF0:
	ldr r4, _081E6CAC @ =0x000015EF
	adds r0, r6, r4
	strb r2, [r0]
	movs r2, #0
	cmp r1, #0x63
	ble _081E6C04
_081E6BFC:
	adds r2, #1
	subs r1, #0x64
	cmp r1, #0x63
	bgt _081E6BFC
_081E6C04:
	ldr r5, _081E6CB0 @ =0x000015EE
	adds r0, r6, r5
	strb r2, [r0]
	movs r2, #0
	cmp r1, #9
	ble _081E6C18
_081E6C10:
	adds r2, #1
	subs r1, #0xa
	cmp r1, #9
	bgt _081E6C10
_081E6C18:
	ldr r3, _081E6CB4 @ =0x000015ED
	adds r0, r6, r3
	strb r2, [r0]
	movs r2, #0
	cmp r1, #0
	ble _081E6C2C
_081E6C24:
	adds r2, #1
	subs r1, #1
	cmp r1, #0
	bgt _081E6C24
_081E6C2C:
	ldr r4, _081E6CB8 @ =0x000015EC
	adds r0, r6, r4
	strb r2, [r0]
_081E6C32:
	ldr r5, _081E6CBC @ =0x00001614
	adds r1, r6, r5
	movs r0, #0
	strb r0, [r1]
_081E6C3A:
	movs r1, #0xb1
	lsls r1, r1, #5
	adds r0, r6, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0xa
	bne _081E6CD4
	movs r3, #0x81
	lsls r3, r3, #4
	adds r1, r6, r3
	ldr r0, [r1]
	movs r2, #1
	orrs r0, r2
	str r0, [r1]
	ldr r4, _081E6CC0 @ =0x00001514
	adds r1, r6, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0xde
	lsls r5, r5, #3
	adds r1, r6, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081E6CC4 @ =0x000014B4
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _081E6CC8 @ =0x00001624
	adds r0, r6, r1
	strb r2, [r0]
	ldr r0, _081E6CCC @ =FUN_081e653c
	movs r1, #0x11
	str r0, [r6, #0x18]
	ldr r3, _081E6CBC @ =0x00001614
	adds r0, r6, r3
	strb r2, [r0]
	ldr r4, _081E6CD0 @ =0x00001616
	adds r0, r6, r4
	strb r1, [r0]
	b _081E6F20
	.align 2, 0
_081E6C90: .4byte 0x0000076A
_081E6C94: .4byte 0x000015E6
_081E6C98: .4byte 0x000015E2
_081E6C9C: .4byte 0x000015E4
_081E6CA0: .4byte 0x00001619
_081E6CA4: .4byte 0x000003E7
_081E6CA8: .4byte 0xFFFFFC18
_081E6CAC: .4byte 0x000015EF
_081E6CB0: .4byte 0x000015EE
_081E6CB4: .4byte 0x000015ED
_081E6CB8: .4byte 0x000015EC
_081E6CBC: .4byte 0x00001614
_081E6CC0: .4byte 0x00001514
_081E6CC4: .4byte 0x000014B4
_081E6CC8: .4byte 0x00001624
_081E6CCC: .4byte FUN_081e653c
_081E6CD0: .4byte 0x00001616
_081E6CD4:
	movs r2, #0x80
	lsls r2, r2, #4
	ldr r5, _081E6CEC @ =0x00001610
	adds r1, r6, r5
	ldr r0, [r1]
	ands r0, r2
	adds r7, r1, #0
	cmp r0, #0
	beq _081E6CF0
	movs r0, #1
	b _081E6CF2
	.align 2, 0
_081E6CEC: .4byte 0x00001610
_081E6CF0:
	movs r0, #0
_081E6CF2:
	adds r5, r0, #0
	cmp r5, #0
	beq _081E6D28
	ldr r0, _081E6D18 @ =FUN_081e6810
	movs r2, #0x15
	str r0, [r6, #0x18]
	ldr r0, _081E6D1C @ =0x00001614
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081E6D20 @ =0x00001616
	adds r0, r6, r1
	strb r2, [r0]
	ldr r1, _081E6D24 @ =0xFFFFF7FF
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	b _081E6F20
	.align 2, 0
_081E6D18: .4byte FUN_081e6810
_081E6D1C: .4byte 0x00001614
_081E6D20: .4byte 0x00001616
_081E6D24: .4byte 0xFFFFF7FF
_081E6D28:
	adds r0, r6, #0
	bl FUN_081e4ab8
	adds r1, r0, #0
	ldr r3, _081E6D58 @ =0x000015E6
	adds r2, r6, r3
	ldrb r4, [r2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _081E6D68
	ldr r1, _081E6D5C @ =0x000015EC
	adds r0, r6, r1
	adds r1, r0, r4
	ldr r2, _081E6D60 @ =0x000015E8
	adds r0, r6, r2
	adds r0, r0, r4
	ldrb r2, [r1]
	ldrb r0, [r0]
	cmp r2, r0
	blo _081E6D64
	strb r5, [r1]
	b _081E6D94
	.align 2, 0
_081E6D58: .4byte 0x000015E6
_081E6D5C: .4byte 0x000015EC
_081E6D60: .4byte 0x000015E8
_081E6D64:
	adds r0, r2, #1
	b _081E6D92
_081E6D68:
	movs r3, #2
	ands r3, r1
	cmp r3, #0
	beq _081E6DB4
	ldr r5, _081E6D88 @ =0x000015EC
	adds r0, r6, r5
	adds r1, r0, r4
	ldrb r0, [r1]
	cmp r0, #0
	bne _081E6D90
	ldr r2, _081E6D8C @ =0x000015E8
	adds r0, r6, r2
	adds r0, r0, r4
	ldrb r0, [r0]
	b _081E6D92
	.align 2, 0
_081E6D88: .4byte 0x000015EC
_081E6D8C: .4byte 0x000015E8
_081E6D90:
	subs r0, #1
_081E6D92:
	strb r0, [r1]
_081E6D94:
	adds r0, r6, #0
	bl FUN_081e3758
	ldr r3, _081E6DB0 @ =0x000015E4
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r1, [r1]
	adds r0, r6, #0
	bl FUN_081e37a0
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _081E6DE8
	.align 2, 0
_081E6DB0: .4byte 0x000015E4
_081E6DB4:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _081E6DD4
	ldr r5, _081E6DCC @ =0x000015E7
	adds r0, r6, r5
	ldrb r0, [r0]
	cmp r4, r0
	blo _081E6DD0
	strb r3, [r2]
	b _081E6DE8
	.align 2, 0
_081E6DCC: .4byte 0x000015E7
_081E6DD0:
	adds r0, r4, #1
	b _081E6DE6
_081E6DD4:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081E6DE8
	cmp r4, #0
	bne _081E6DE4
	movs r0, #3
	b _081E6DE6
_081E6DE4:
	subs r0, r4, #1
_081E6DE6:
	strb r0, [r2]
_081E6DE8:
	ldr r1, _081E6E88 @ =0x000015E6
	adds r0, r6, r1
	ldrb r1, [r0]
	cmp r1, r4
	beq _081E6E1A
	lsls r1, r1, #3
	movs r0, #0x18
	subs r0, r0, r1
	movs r2, #0xed
	lsls r2, r2, #3
	adds r1, r6, r2
	movs r2, #0
	strh r0, [r1]
	ldr r3, _081E6E8C @ =0x0000076A
	adds r0, r6, r3
	strh r2, [r0]
	ldr r4, _081E6E90 @ =0x000015E4
	adds r0, r6, r4
	ldrh r1, [r0]
	adds r0, r6, #0
	bl FUN_081e37a0
	movs r0, #0xdc
	bl PlaySound_082406e0
_081E6E1A:
	ldr r0, _081E6E94 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r4, #1
	movs r3, #1
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	bne _081E6E32
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _081E6EB6
_081E6E32:
	ldr r0, _081E6E98 @ =0x030046A0
	ldr r0, [r0]
	movs r5, #0x91
	lsls r5, r5, #4
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r5, _081E6E90 @ =0x000015E4
	adds r2, r6, r5
	ldrh r1, [r2]
	cmp r0, r1
	blt _081E6EAC
	ldr r0, _081E6E9C @ =FUN_081e7414
	movs r1, #4
	str r0, [r6, #0x18]
	adds r5, #0x30
	adds r0, r6, r5
	strb r4, [r0]
	ldr r4, _081E6EA0 @ =0x00001616
	adds r0, r6, r4
	strb r1, [r0]
	movs r5, #0xea
	lsls r5, r5, #3
	adds r1, r6, r5
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	ldrh r1, [r2]
	ldr r2, _081E6EA4 @ =0x000015E2
	adds r0, r6, r2
	strh r1, [r0]
	ldrh r1, [r0]
	adds r0, r6, #0
	bl FUN_081e37a0
	ldr r1, _081E6EA8 @ =0xFFFDFFFF
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081E6F20
	.align 2, 0
_081E6E88: .4byte 0x000015E6
_081E6E8C: .4byte 0x0000076A
_081E6E90: .4byte 0x000015E4
_081E6E94: .4byte 0x030044E0
_081E6E98: .4byte 0x030046A0
_081E6E9C: .4byte FUN_081e7414
_081E6EA0: .4byte 0x00001616
_081E6EA4: .4byte 0x000015E2
_081E6EA8: .4byte 0xFFFDFFFF
_081E6EAC:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _081E6F14
_081E6EB6:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081E6F14
	ldr r0, _081E6F00 @ =FUN_081e7414
	movs r1, #4
	str r0, [r6, #0x18]
	ldr r5, _081E6F04 @ =0x00001614
	adds r0, r6, r5
	strb r4, [r0]
	ldr r2, _081E6F08 @ =0x00001616
	adds r0, r6, r2
	strb r1, [r0]
	movs r4, #0xea
	lsls r4, r4, #3
	adds r1, r6, r4
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	subs r5, #0x32
	adds r4, r6, r5
	ldrh r1, [r4]
	adds r0, r6, #0
	bl FUN_081e37a0
	ldrh r1, [r4]
	ldr r2, _081E6F0C @ =0x000015E4
	adds r0, r6, r2
	strh r1, [r0]
	ldr r1, _081E6F10 @ =0xFFFDFFFF
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081E6F20
	.align 2, 0
_081E6F00: .4byte FUN_081e7414
_081E6F04: .4byte 0x00001614
_081E6F08: .4byte 0x00001616
_081E6F0C: .4byte 0x000015E4
_081E6F10: .4byte 0xFFFDFFFF
_081E6F14:
	adds r0, r6, #0
	bl FUN_081e2ee8
	adds r0, r6, #0
	bl FUN_081e4a60
_081E6F20:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
