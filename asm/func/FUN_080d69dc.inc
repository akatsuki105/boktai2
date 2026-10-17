	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _080D6A10
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_080cc3d4
	cmp r0, #0
	bne _080D6A0E
	ldr r0, [r5, #0x3c]
	cmp r0, #0
	bne _080D6A10
	movs r2, #0xde
	lsls r2, r2, #1
	adds r4, r5, r2
	adds r1, r5, #0
	adds r1, #0x2c
	adds r0, r4, #0
	bl Map_InitMoverTile
_080D6A0E:
	str r4, [r5, #0x3c]
_080D6A10:
	adds r0, r5, #0
	adds r0, #0x24
	bl Mover_ApplyMove
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D6A34
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	b _080D6A52
_080D6A34:
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ldr r0, _080D6A6C @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r5, #0
	adds r1, #0x2c
	movs r2, #0
	bl Hitbox_SetPos
_080D6A52:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D6A70
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _080D6A7C
	.align 2, 0
_080D6A6C: .4byte 0x0000FFFB
_080D6A70:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_080D6A7C:
	str r1, [r0]
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #2
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D6A96
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	b _080D6A9C
_080D6A96:
	ldr r0, [r4]
	ldr r1, _080D6AB8 @ =0xFFFFFDFF
	ands r0, r1
_080D6A9C:
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D6ABC
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _080D6AC6
	.align 2, 0
_080D6AB8: .4byte 0xFFFFFDFF
_080D6ABC:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_080D6AC6:
	str r1, [r0]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D6AE4
	ldr r1, _080D6AE0 @ =0x0000060C
	adds r0, r5, r1
	bl ParticleShadow_Hide
	b _080D6AEC
	.align 2, 0
_080D6AE0: .4byte 0x0000060C
_080D6AE4:
	ldr r2, _080D6B1C @ =0x0000060C
	adds r0, r5, r2
	bl ParticleShadow_Show
_080D6AEC:
	movs r1, #0xfe
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r5, #0x2e]
	adds r0, r0, r2
	strh r0, [r5, #0x2e]
	adds r2, r5, #0
	adds r2, #0xa8
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r5, #0
	adds r1, #0xaa
	ldr r2, _080D6B20 @ =0x000003F6
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D6B1C: .4byte 0x0000060C
_080D6B20: .4byte 0x000003F6
