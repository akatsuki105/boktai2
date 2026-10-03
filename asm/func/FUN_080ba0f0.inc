	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	mov sl, r0
	adds r7, r1, #0
	ldr r0, _080BA114 @ =0x030046A0
	ldr r0, [r0]
	adds r1, r0, #0
	adds r1, #0x5c
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bge _080BA118
	movs r0, #0
	b _080BA126
	.align 2, 0
_080BA114: .4byte 0x030046A0
_080BA118:
	movs r2, #0
	ldrsh r0, [r1, r2]
	bl GetInventoryArmor
	lsls r0, r0, #3
	ldr r1, _080BA138 @ =0x08DAA7B0
	adds r0, r0, r1
_080BA126:
	bl FUN_0807a70c
	adds r4, r0, #0
	cmp r7, #0
	bge _080BA13C
	adds r0, r4, #0
	movs r6, #0
	b _080BA154
	.align 2, 0
_080BA138: .4byte 0x08DAA7B0
_080BA13C:
	lsls r0, r7, #3
	ldr r1, _080BA1B4 @ =0x08DAA7B0
	adds r0, r0, r1
	bl FUN_0807a70c
	movs r6, #0
	cmp r0, r4
	beq _080BA154
	movs r6, #2
	cmp r0, r4
	ble _080BA154
	movs r6, #1
_080BA154:
	add r4, sp, #0x24
	adds r1, r4, #0
	bl FUN_080ba0c0
	movs r0, #0x18
	add r0, sl
	mov r8, r0
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r6, r0, #1
	add r1, sp, #0x24
	mov sb, r1
	ldr r4, _080BA1B8 @ =0x00001158
	add r4, sl
	movs r5, #2
_080BA172:
	mov r0, sb
	adds r0, #4
	mov sb, r0
	subs r0, #4
	ldm r0!, {r2}
	adds r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl MainSprite_SetPose
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080BA172
	ldr r0, _080BA1BC @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x58
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sp
	bl FUN_08242b28
	mov r0, sp
	bl FUN_0807a6cc
	adds r5, r0, #0
	cmp r7, #0
	bge _080BA1C0
	movs r6, #0
	b _080BA1DA
	.align 2, 0
_080BA1B4: .4byte 0x08DAA7B0
_080BA1B8: .4byte 0x00001158
_080BA1BC: .4byte 0x030046A0
_080BA1C0:
	lsls r1, r7, #3
	ldr r0, _080BA218 @ =0x08DAA7B0
	adds r1, r1, r0
	mov r0, sp
	bl FUN_0807a5d8
	movs r6, #0
	cmp r0, r5
	beq _080BA1DA
	movs r6, #2
	cmp r0, r5
	ble _080BA1DA
	movs r6, #1
_080BA1DA:
	add r1, sp, #0x24
	bl FUN_080ba0c0
	lsls r0, r6, #2
	adds r0, r0, r6
	lsls r6, r0, #1
	add r7, sp, #0x24
	ldr r4, _080BA21C @ =0x00001038
	add r4, sl
	movs r5, #2
_080BA1EE:
	ldm r7!, {r2}
	adds r2, r2, r6
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r4, #0
	mov r1, r8
	movs r3, #1
	bl MainSprite_SetPose
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _080BA1EE
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BA218: .4byte 0x08DAA7B0
_080BA21C: .4byte 0x00001038
