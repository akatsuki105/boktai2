	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #9
	beq _08082DD0
	adds r0, r4, #0
	movs r1, #9
	movs r2, #0
	bl FUN_08080e0c
	ldr r2, _08082DE8 @ =0x00000951
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_08082DD0:
	ldr r3, _08082DEC @ =0x0000037D
	adds r0, r4, r3
	ldrb r2, [r0]
	cmp r2, #1
	bne _08082DDC
	b _08082F30
_08082DDC:
	cmp r2, #1
	bgt _08082DF0
	cmp r2, #0
	beq _08082DFE
	b _08083012
	.align 2, 0
_08082DE8: .4byte 0x00000951
_08082DEC: .4byte 0x0000037D
_08082DF0:
	cmp r2, #2
	bne _08082DF6
	b _08082F84
_08082DF6:
	cmp r2, #3
	bne _08082DFC
	b _08082FE8
_08082DFC:
	b _08083012
_08082DFE:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r3, r4, r0
	ldrb r0, [r3]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _08082E60
	movs r1, #4
	strb r1, [r3]
	ldr r3, _08082E50 @ =0x000002E6
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _08082E54 @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
	movs r3, #0x93
	lsls r3, r3, #4
	adds r2, r4, r3
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	subs r0, #0x14
	strh r0, [r2]
	ldr r0, _08082E58 @ =0x00000932
	adds r1, r4, r0
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldr r0, _08082E5C @ =0x00000934
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #0x3c
	b _08082E9A
	.align 2, 0
_08082E50: .4byte 0x000002E6
_08082E54: .4byte 0x000002E7
_08082E58: .4byte 0x00000932
_08082E5C: .4byte 0x00000934
_08082E60:
	strb r2, [r3]
	ldr r1, _08082EBC @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	ldr r3, _08082EC0 @ =0x000002E7
	adds r0, r4, r3
	strb r2, [r0]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r2]
	ldr r2, _08082EC4 @ =0x00000932
	adds r1, r4, r2
	movs r3, #0xa5
	lsls r3, r3, #1
	adds r0, r3, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _08082EC8 @ =0x00000934
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, #0x14
_08082E9A:
	strh r0, [r1]
	movs r1, #0xcf
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _08082ECC
	ldr r2, _08082EBC @ =0x000002E6
	adds r1, r4, r2
	movs r0, #1
	b _08082ED2
	.align 2, 0
_08082EBC: .4byte 0x000002E6
_08082EC0: .4byte 0x000002E7
_08082EC4: .4byte 0x00000932
_08082EC8: .4byte 0x00000934
_08082ECC:
	ldr r3, _08082F1C @ =0x000002E6
	adds r1, r4, r3
	movs r0, #0
_08082ED2:
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #9
	movs r2, #1
	bl FUN_08080e0c
	ldr r0, _08082F20 @ =0x0000095E
	adds r1, r4, r0
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #2
	strh r0, [r1]
	ldr r0, _08082F24 @ =0x0000036E
	bl PlaySound_082406e0
	adds r1, r4, #0
	adds r1, #0x2c
	movs r3, #0x93
	lsls r3, r3, #4
	adds r2, r4, r3
	ldr r3, _08082F28 @ =0x000003BA
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r3, #1
	bl Entity080abd14_Create
	ldr r0, _08082F2C @ =0x00000477
	adds r1, r4, r0
	movs r0, #0x3c
	strb r0, [r1]
	b _08083012
	.align 2, 0
_08082F1C: .4byte 0x000002E6
_08082F20: .4byte 0x0000095E
_08082F24: .4byte 0x0000036E
_08082F28: .4byte 0x000003BA
_08082F2C: .4byte 0x00000477
_08082F30:
	ldr r2, _08082F80 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _08082F52
	movs r0, #0x20
	strh r0, [r1]
_08082F52:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08083012
	movs r0, #0xcb
	bl PlaySound_082406e0
	adds r0, r4, #0
	movs r1, #9
	movs r2, #2
	bl FUN_08080e0c
	b _08083012
	.align 2, 0
_08082F80: .4byte 0x0000095E
_08082F84:
	movs r1, #0xeb
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	ldr r2, _08082FDC @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0x96
	lsls r3, r3, #4
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	ldr r3, _08082FE0 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _08082FB6
	movs r0, #0x20
	strh r0, [r1]
_08082FB6:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	ldr r3, _08082FE4 @ =0x0000037E
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ands r0, r2
	cmp r0, #0x17
	bls _08083012
	adds r0, r4, #0
	movs r1, #9
	movs r2, #3
	bl FUN_08080e0c
	b _08083012
	.align 2, 0
_08082FDC: .4byte 0x0000095E
_08082FE0: .4byte 0x0000FFFF
_08082FE4: .4byte 0x0000037E
_08082FE8:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_08080cac
	cmp r0, #0
	beq _08083012
	adds r0, r4, #0
	bl LinkPlayer_SetAnimFacing
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_08080e0c
_08083012:
	add sp, #4
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
