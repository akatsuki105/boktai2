	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	mov sb, r2
	ldr r2, _081974A8 @ =0x00000CE8
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r3, #0x36
	ldrsh r4, [r5, r3]
	ldr r6, _081974AC @ =0x00000CCC
	adds r2, r5, r6
	movs r3, #0
	ldrsh r2, [r2, r3]
	adds r6, #2
	adds r3, r5, r6
	ldrb r3, [r3]
	lsrs r1, r1, #2
	movs r6, #1
	mov r8, r6
	ands r1, r6
	str r1, [sp]
	adds r1, r4, #0
	bl HUD_ShowEnemyGauge
	add r6, sp, #0xc
	movs r7, #0
	str r7, [sp, #8]
	add r0, sp, #8
	adds r1, r6, #0
	ldr r2, _081974B0 @ =0x05000002
	bl CpuSet
	ldr r0, _081974B4 @ =0x00000CE4
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _08197498
	ldr r0, _081974B8 @ =0x0000FF88
	strh r0, [r6, #2]
	ldr r1, _081974BC @ =0x00000BE4
	adds r0, r5, r1
	ldrh r1, [r4]
	ldr r2, _081974C0 @ =0x00000AFC
	adds r3, r5, r2
	str r6, [sp]
	mov r6, r8
	str r6, [sp, #4]
	mov r2, sb
	bl CreateDamageNumber
	strh r7, [r4]
_08197498:
	add sp, #0x14
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081974A8: .4byte 0x00000CE8
_081974AC: .4byte 0x00000CCC
_081974B0: .4byte 0x05000002
_081974B4: .4byte 0x00000CE4
_081974B8: .4byte 0x0000FF88
_081974BC: .4byte 0x00000BE4
_081974C0: .4byte 0x00000AFC
