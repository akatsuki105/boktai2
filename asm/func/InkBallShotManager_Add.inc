	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov r8, r0
	adds r7, r1, #0
	adds r6, r2, #0
	mov sb, r3
	ldr r0, _08202F4C @ =0x03000218
	ldr r5, [r0]
	bl InkBallShotManager_FindFree
	adds r4, r0, #0
	cmp r4, #0
	beq _08202FE8
	adds r0, r5, #0
	adds r0, #0x3c
	ldrb r1, [r0]
	adds r1, #1
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #0
	bl InkBallShot_SetState
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	cmp r7, #0
	bne _08202F54
	adds r1, r4, #0
	adds r1, #0xdc
	str r7, [sp, #4]
	add r0, sp, #4
	ldr r2, _08202F50 @ =0x05000002
	bl CpuSet
	b _08202F60
	.align 2, 0
_08202F4C: .4byte 0x03000218
_08202F50: .4byte 0x05000002
_08202F54:
	adds r2, r4, #0
	adds r2, #0xdc
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r2]
	str r1, [r2, #4]
_08202F60:
	cmp r6, #0
	bne _08202F84
	adds r1, r4, #0
	adds r1, #0xe4
	str r6, [sp, #4]
	add r0, sp, #4
	ldr r2, _08202F80 @ =0x05000002
	bl CpuSet
	adds r0, r4, #0
	adds r0, #0xfe
	strb r6, [r0]
	subs r0, #2
	strh r6, [r0]
	b _08202FA0
	.align 2, 0
_08202F80: .4byte 0x05000002
_08202F84:
	adds r2, r4, #0
	adds r2, #0xe4
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r1, [r7]
	adds r0, r4, #0
	adds r0, #0xfc
	strh r1, [r0]
	adds r1, r4, #0
	adds r1, #0xfe
	movs r0, #1
	strb r0, [r1]
_08202FA0:
	adds r1, r4, #0
	adds r1, #0xec
	ldr r0, [sp, #0x30]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x34]
	strh r0, [r1]
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r0, [sp, #0x2c]
	str r0, [sp]
	adds r0, r4, #0
	mov r1, sb
	ldr r2, [sp, #0x24]
	ldr r3, [sp, #0x28]
	bl InkBallShot_InitHitbox
	adds r1, r4, #0
	adds r1, #0xf0
	ldr r0, [sp, #0x38]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x3c]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x40]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x44]
	strh r0, [r1]
	adds r1, #2
	ldr r0, [sp, #0x48]
	strh r0, [r1]
_08202FE8:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
