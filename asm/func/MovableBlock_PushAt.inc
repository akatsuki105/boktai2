	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r5, r0, #0
	str r1, [sp]
	ldr r0, _08003D38 @ =0x03000020
	ldr r0, [r0]
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _08003D3C
	movs r0, #1
	rsbs r0, r0, #0
	b _08003F14
	.align 2, 0
_08003D38: .4byte 0x03000020
_08003D3C:
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08003D60
	cmp r1, #0
	blt _08003D60
	ldr r0, _08003D64 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08003D60
	ldr r0, _08003D68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08003D6C
_08003D60:
	movs r4, #0
	b _08003D7A
	.align 2, 0
_08003D64: .4byte 0x030046A8
_08003D68: .4byte 0x030046AC
_08003D6C:
	ldr r0, _08003D8C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08003D7A:
	adds r0, r4, #0
	movs r1, #1
	bl Map_FindTileOverride
	cmp r0, #0
	beq _08003D90
	adds r0, #4
	b _08003D9C
	.align 2, 0
_08003D8C: .4byte 0x030046A4
_08003D90:
	ldr r0, _08003DC8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08003D9C:
	str r0, [sp, #0xc]
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08003DC2
	cmp r1, #0
	blt _08003DC2
	ldr r0, _08003DCC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08003DC2
	ldr r0, _08003DD0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08003DD4
_08003DC2:
	movs r0, #0
	b _08003DE2
	.align 2, 0
_08003DC8: .4byte 0x030046A4
_08003DCC: .4byte 0x030046A8
_08003DD0: .4byte 0x030046AC
_08003DD4:
	ldr r0, _08003DF8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_08003DE2:
	str r0, [sp, #8]
	movs r1, #0
	str r1, [sp, #4]
	ldr r2, [sp]
	cmp r2, #1
	beq _08003E1C
	cmp r2, #1
	bgt _08003DFC
	cmp r2, #0
	beq _08003E08
	b _08003E3A
	.align 2, 0
_08003DF8: .4byte 0x030046A4
_08003DFC:
	ldr r0, [sp]
	cmp r0, #2
	beq _08003E22
	cmp r0, #3
	beq _08003E34
	b _08003E3A
_08003E08:
	ldr r0, _08003E18 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r1, #4
	ldrsh r0, [r0, r1]
	rsbs r0, r0, #0
	b _08003E38
	.align 2, 0
_08003E18: .4byte 0x030046A4
_08003E1C:
	movs r2, #1
	str r2, [sp, #4]
	b _08003E3A
_08003E22:
	ldr r0, _08003E30 @ =0x030046A4
	ldr r0, [r0]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	str r1, [sp, #4]
	b _08003E3A
	.align 2, 0
_08003E30: .4byte 0x030046A4
_08003E34:
	movs r0, #1
	rsbs r0, r0, #0
_08003E38:
	str r0, [sp, #4]
_08003E3A:
	ldr r1, [sp, #0x10]
	ldr r5, [r1, #0x70]
	movs r2, #0
	mov sb, r2
	ldrh r0, [r1, #0x18]
	cmp sb, r0
	bge _08003F12
	movs r3, #0xf
	adds r7, r5, #0
	adds r7, #0x25
	adds r6, r5, #0
	adds r6, #0xba
_08003E52:
	ldrb r0, [r5, #0x1e]
	cmp r0, #0
	beq _08003EFC
	ldrh r0, [r5, #4]
	cmp r0, #0
	bne _08003EFC
	movs r1, #0xbc
	adds r1, r1, r5
	mov r8, r1
	ldr r2, [sp, #8]
	ldr r0, [sp, #4]
	adds r4, r2, r0
	mov sl, r6
	ldrh r1, [r6]
	cmp r4, r1
	bne _08003EFC
	ldr r2, [sp, #0xc]
	ldrb r0, [r2]
	adds r1, r3, #0
	ands r1, r0
	adds r1, #1
	ldrb r2, [r6, #2]
	adds r0, r3, #0
	ands r0, r2
	cmp r1, r0
	bne _08003EFC
	adds r0, r4, #0
	movs r1, #1
	str r3, [sp, #0x14]
	bl Map_FindTileOverride
	ldr r3, [sp, #0x14]
	cmp r0, #0
	beq _08003E9A
	adds r0, #4
	b _08003EA6
_08003E9A:
	ldr r0, _08003EF8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08003EA6:
	ldrb r0, [r0]
	adds r1, r3, #0
	ands r1, r0
	mov r0, r8
	ldrb r2, [r0]
	adds r0, r3, #0
	ands r0, r2
	cmp r1, r0
	bne _08003EFC
	adds r0, r5, #0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r0, #0
	beq _08003EC8
	ldrb r0, [r7]
	cmp r0, #0
	beq _08003F12
_08003EC8:
	mov r2, sl
	ldrh r1, [r2]
	adds r0, r5, #0
	ldr r2, [sp]
	bl MovableBlock_TryMove
	adds r4, r0, #0
	cmp r4, #0
	ble _08003EF4
	ldrb r0, [r5]
	bl MovableBlock_PlayPushSound
	ldrb r0, [r5]
	cmp r0, #1
	bne _08003EEA
	movs r4, #1
	rsbs r4, r4, #0
_08003EEA:
	ldrb r0, [r7]
	cmp r0, #0
	beq _08003EF4
	subs r0, #1
	strb r0, [r7]
_08003EF4:
	adds r0, r4, #0
	b _08003F14
	.align 2, 0
_08003EF8: .4byte 0x030046A4
_08003EFC:
	movs r0, #0xce
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r6, r6, r0
	adds r5, r5, r0
	movs r1, #1
	add sb, r1
	ldr r2, [sp, #0x10]
	ldrh r2, [r2, #0x18]
	cmp sb, r2
	blt _08003E52
_08003F12:
	movs r0, #0
_08003F14:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
