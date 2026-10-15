	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _081E428C @ =0x00000BC4
	adds r0, r0, r7
	mov r8, r0
	add r4, sp, #4
	movs r0, #0
	str r0, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _081E4290 @ =0x05000002
	bl CpuSet
	ldr r0, _081E4294 @ =0x0000CB05
	ldr r1, _081E4298 @ =0x00005D04
	bl GetFile
	adds r1, r0, #0
	mov sl, r4
	cmp r1, #0
	bne _081E421A
	b _081E432E
_081E421A:
	ldr r2, _081E429C @ =0x0000158C
	adds r0, r7, r2
	str r1, [r0]
	subs r2, #0x20
	adds r0, r7, r2
	bl OpenMainSpriteFile
	movs r5, #0
	mov sb, r5
	ldr r0, _081E42A0 @ =0x00000E86
	adds r6, r7, r0
	ldr r1, _081E42A4 @ =0x00000E4C
	adds r7, r7, r1
	mov r4, r8
_081E4236:
	movs r1, #3
	ands r1, r5
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	mov r2, sl
	strh r0, [r2]
	asrs r1, r5, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	add r1, sp, #4
	strh r0, [r1, #2]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08242b14
	ldrb r2, [r4]
	adds r0, r7, #0
	ldr r1, _081E42A8 @ =0x000009A8
	add r1, r8
	bl MainSprite_LoadPose
	adds r0, r5, #0
	bl FUN_08243180
	cmp r0, #0
	bne _081E42B0
	movs r0, #0xb8
	lsls r0, r0, #2
	strh r0, [r6]
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, r8
	add r1, sb
	ldr r0, _081E42AC @ =0x03003584
	ldr r0, [r0]
	movs r2, #0xb8
	lsls r2, r2, #7
	b _081E42C2
	.align 2, 0
_081E428C: .4byte 0x00000BC4
_081E4290: .4byte 0x05000002
_081E4294: .4byte 0x0000CB05
_081E4298: .4byte 0x00005D04
_081E429C: .4byte 0x0000158C
_081E42A0: .4byte 0x00000E86
_081E42A4: .4byte 0x00000E4C
_081E42A8: .4byte 0x000009A8
_081E42AC: .4byte 0x03003584
_081E42B0:
	ldr r0, _081E4340 @ =0x000002DF
	strh r0, [r6]
	movs r1, #0xb4
	lsls r1, r1, #2
	add r1, r8
	add r1, sb
	ldr r0, _081E4344 @ =0x03003584
	ldr r0, [r0]
	ldr r2, _081E4348 @ =0x00005BE0
_081E42C2:
	adds r0, r0, r2
	str r0, [r1]
	movs r0, #0xa4
	lsls r0, r0, #2
	add r0, r8
	add r0, sb
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	movs r0, #0x60
	add sb, r0
	adds r6, #0x60
	adds r7, #0x60
	adds r4, #0x24
	adds r5, #1
	cmp r5, #0xf
	ble _081E4236
	movs r0, #0x30
	mov r1, sl
	strh r0, [r1]
	add r1, sp, #4
	movs r0, #0x48
	strh r0, [r1, #2]
	ldr r4, _081E434C @ =0x00000888
	add r4, r8
	movs r6, #0xc0
	lsls r6, r6, #3
	movs r5, #1
_081E42FC:
	adds r0, r4, #0
	ldr r1, _081E4350 @ =0x000009A8
	add r1, r8
	movs r2, #0
	bl MainSprite_LoadPose
	movs r2, #0xa4
	lsls r2, r2, #2
	add r2, r8
	adds r2, r2, r6
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	mov r2, sl
	ldrh r0, [r2]
	strh r0, [r4, #0x20]
	add r0, sp, #4
	ldrh r0, [r0, #2]
	strh r0, [r4, #0x22]
	adds r4, #0x60
	adds r6, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081E42FC
_081E432E:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E4340: .4byte 0x000002DF
_081E4344: .4byte 0x03003584
_081E4348: .4byte 0x00005BE0
_081E434C: .4byte 0x00000888
_081E4350: .4byte 0x000009A8
