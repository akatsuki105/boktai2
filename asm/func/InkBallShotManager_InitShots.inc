	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x18
	ldr r1, _08203474 @ =0x00002E78
	adds r0, r4, #0
	bl Video_GetAuxSprite
	ldr r1, _08203478 @ =0x00000236
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	ldr r0, _0820347C @ =0x0000922E
	ldr r1, _08203480 @ =0x000038E2
	bl GetFile
	str r0, [r7, #0x34]
	mov sb, r0
	adds r5, r7, #0
	adds r5, #0x40
	movs r6, #0
	movs r0, #7
	mov r8, r0
_08203406:
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x18
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	adds r0, #0x2c
	str r6, [sp]
	mov r1, sb
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	adds r0, r5, #0
	bl InkBallShot_InitHurtbox
	str r6, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl InkBallShot_InitHitbox
	str r6, [sp, #4]
	add r0, sp, #4
	adds r4, r5, #0
	adds r4, #0xdc
	adds r1, r4, #0
	ldr r2, _08203484 @ =0x05000002
	bl CpuSet
	strh r6, [r4, #0x10]
	strh r6, [r4, #0x12]
	movs r0, #0x82
	lsls r0, r0, #1
	adds r5, r5, r0
	movs r0, #1
	rsbs r0, r0, #0
	add r8, r0
	mov r0, r8
	cmp r0, #0
	bge _08203406
	movs r0, #0
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08203474: .4byte 0x00002E78
_08203478: .4byte 0x00000236
_0820347C: .4byte 0x0000922E
_08203480: .4byte 0x000038E2
_08203484: .4byte 0x05000002
