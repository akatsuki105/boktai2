	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _08185D5C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08185D60
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08185D62
	.align 2, 0
_08185D5C: .4byte 0x0000046D
_08185D60:
	movs r0, #0
_08185D62:
	cmp r0, #0
	bne _08185D68
	b _08185F5E
_08185D68:
	adds r2, r5, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	ldr r1, _08185DB0 @ =0x0000FFF7
	ands r0, r1
	strh r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #4
	ldr r1, _08185DB4 @ =0x00000474
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r5, #0
	movs r1, #0x14
	bl Enemy_PlayAnimNoFacing
	ldr r2, _08185DB8 @ =0x0000047A
	adds r0, r5, r2
	ldrh r0, [r0]
	adds r3, r0, #3
	ldr r6, _08185DBC @ =0x0000025D
	adds r0, r5, r6
	ldrb r1, [r0]
	adds r7, r0, #0
	cmp r1, #0
	bne _08185DC0
	ldr r0, [r5, #0x44]
	adds r0, #0x2c
	adds r1, r3, #0
	bl Video_SetAuxSpritePltt
	b _08185DCC
	.align 2, 0
_08185DB0: .4byte 0x0000FFF7
_08185DB4: .4byte 0x00000474
_08185DB8: .4byte 0x0000047A
_08185DBC: .4byte 0x0000025D
_08185DC0:
	ldr r2, [r5, #0x44]
	ldr r0, _08185DE0 @ =0x03003584
	lsls r1, r3, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08185DCC:
	movs r2, #1
	ldrb r0, [r7]
	cmp r0, #0
	bne _08185DE4
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _08185DEE
	.align 2, 0
_08185DE0: .4byte 0x03003584
_08185DE4:
	ldr r1, [r5, #0x44]
	adds r1, #0x20
	ldr r0, [r1, #8]
	orrs r0, r2
	str r0, [r1, #8]
_08185DEE:
	ldr r1, [r5, #0x44]
	movs r0, #3
	strb r0, [r1, #7]
	adds r4, r5, #0
	adds r4, #8
	movs r0, #0x8a
	lsls r0, r0, #1
	str r0, [sp]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #2
	movs r3, #1
	bl Entity081ea120_Spawn
	ldr r0, _08185E38 @ =0x000001D9
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl Enemy_Deactivate
	ldr r1, _08185E3C @ =0x0000047A
	adds r0, r5, r1
	ldrh r1, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	adds r1, r1, r0
	ldrb r0, [r7]
	mov r8, r4
	cmp r0, #0
	bne _08185E40
	ldr r0, [r5, #0x44]
	adds r0, #0x2c
	bl Video_SetAuxSpritePltt
	b _08185E4C
	.align 2, 0
_08185E38: .4byte 0x000001D9
_08185E3C: .4byte 0x0000047A
_08185E40:
	ldr r2, [r5, #0x44]
	ldr r0, _08185ED4 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_08185E4C:
	ldr r3, _08185ED8 @ =Enemy_ClearStateBegun
	movs r1, #0x10
	ldr r6, _08185EDC @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	movs r4, #1
	strb r4, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r6, #0xe4
	lsls r6, r6, #1
	adds r0, r5, r6
	movs r3, #0
	strh r2, [r0]
	movs r1, #3
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _08185EE0 @ =0x00000469
	adds r0, r5, r1
	strb r3, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r3, [r0]
	adds r1, #0x1b
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08185EE4 @ =0x0000046C
	adds r0, r5, r2
	strb r4, [r0]
	mov r6, r8
	adds r1, r5, #0
	adds r1, #0x9c
	ldr r0, [r1, #8]
	ldrh r0, [r0]
	strh r0, [r5, #8]
	ldr r0, [r1, #8]
	ldrh r1, [r0, #2]
	strh r1, [r6, #4]
	ldrh r0, [r5, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08185ECE
	cmp r1, #0
	blt _08185ECE
	ldr r0, _08185EE8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08185ECE
	ldr r0, _08185EEC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08185EF0
_08185ECE:
	movs r4, #0
	b _08185EFE
	.align 2, 0
_08185ED4: .4byte 0x03003584
_08185ED8: .4byte Enemy_ClearStateBegun
_08185EDC: .4byte 0x0000046D
_08185EE0: .4byte 0x00000469
_08185EE4: .4byte 0x0000046C
_08185EE8: .4byte 0x030046A8
_08185EEC: .4byte 0x030046AC
_08185EF0:
	ldr r0, _08185F10 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08185EFE:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08185F14
	adds r0, #4
	b _08185F20
	.align 2, 0
_08185F10: .4byte 0x030046A4
_08185F14:
	ldr r0, _08185F34 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08185F20:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08185F38
	cmp r2, #2
	beq _08185F3C
	b _08185F40
	.align 2, 0
_08185F34: .4byte 0x030046A4
_08185F38:
	ldrb r0, [r6, #4]
	b _08185F3E
_08185F3C:
	ldrb r0, [r6]
_08185F3E:
	subs r1, r1, r0
_08185F40:
	strh r1, [r6, #2]
	ldrb r0, [r7]
	cmp r0, #0
	bne _08185F54
	ldr r2, [r5, #0x44]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _08185F5E
_08185F54:
	ldr r2, [r5, #0x44]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_08185F5E:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
