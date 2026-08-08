	push {r4, r5, lr}
	sub sp, #0x14
	adds r4, r0, #0
	movs r1, #4
	bl FUN_08060c40
	ldr r1, _08069D94 @ =0x0000037D
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	bne _08069D88
	b _08069E94
_08069D88:
	cmp r5, #1
	bgt _08069D98
	cmp r5, #0
	beq _08069DA6
	b _08069F54
	.align 2, 0
_08069D94: .4byte 0x0000037D
_08069D98:
	cmp r5, #2
	bne _08069D9E
	b _08069ED0
_08069D9E:
	cmp r5, #3
	bne _08069DA4
	b _08069F44
_08069DA4:
	b _08069F54
_08069DA6:
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r2, [sp, #0xc]
	asrs r1, r2, #0x10
	adds r1, #0x96
	lsls r1, r1, #0x10
	ldr r0, _08069DEC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	bl FUN_0823bac8
	movs r2, #0xfc
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08069DF4
	movs r0, #4
	str r0, [sp]
	ldr r0, _08069DF0 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #0x10
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #3
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	b _08069E0C
	.align 2, 0
_08069DEC: .4byte 0x0000FFFF
_08069DF0: .4byte 0x00001FFF
_08069DF4:
	movs r0, #4
	str r0, [sp]
	ldr r0, _08069E3C @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #3
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_08069E0C:
	ldr r0, _08069E40 @ =0x000001AD
	bl PlaySound_082406e0
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _08069E4C
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _08069E44 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _08069E48 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _08069E5C
	.align 2, 0
_08069E3C: .4byte 0x00001FFF
_08069E40: .4byte 0x000001AD
_08069E44: .4byte 0x000002E6
_08069E48: .4byte 0x000002E7
_08069E4C:
	lsrs r1, r1, #0x19
	ldr r2, _08069E88 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r1, _08069E8C @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
_08069E5C:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #1
	bl FUN_08060b84
	ldr r0, _08069E90 @ =0x000003F6
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	b _08069F54
	.align 2, 0
_08069E88: .4byte 0x000002E6
_08069E8C: .4byte 0x000002E7
_08069E90: .4byte 0x000003F6
_08069E94:
	ldr r2, _08069EC8 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _08069F54
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #2
	bl FUN_08060b84
	ldr r0, _08069ECC @ =0x000003F6
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xef
	strb r5, [r0]
	movs r0, #0xd7
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _08069F54
	.align 2, 0
_08069EC8: .4byte 0x0000037E
_08069ECC: .4byte 0x000003F6
_08069ED0:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r5, r4, r1
	ldrb r0, [r5]
	movs r1, #0x12
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08060a24
	ldr r2, _08069F0C @ =0x000003F6
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #0x3c
	strh r0, [r1]
	ldr r1, _08069F10 @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #4
	bne _08069F1E
	ldrb r0, [r5]
	cmp r0, #5
	bne _08069F18
	ldr r0, _08069F14 @ =0x000002ED
	bl PlaySound_082406e0
	b _08069F1E
	.align 2, 0
_08069F0C: .4byte 0x000003F6
_08069F10: .4byte 0x0000037E
_08069F14: .4byte 0x000002ED
_08069F18:
	ldr r0, _08069F3C @ =0x00000305
	bl PlaySound_082406e0
_08069F1E:
	ldr r2, _08069F40 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _08069F54
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #3
	bl FUN_08060b84
	b _08069F54
	.align 2, 0
_08069F3C: .4byte 0x00000305
_08069F40: .4byte 0x0000037E
_08069F44:
	ldr r0, _08069F5C @ =0x000003F6
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08060c40
_08069F54:
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08069F5C: .4byte 0x000003F6
