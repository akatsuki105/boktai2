	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r0, #0
	strh r1, [r6, #0x18]
	strh r2, [r6, #0x1a]
	str r0, [r6, #0x1c]
	str r0, [r6, #0x28]
	movs r0, #0x6d
	bl VM_SeekToNamedArg
	cmp r0, #0
	beq _08002EB8
	bl VM_GetValue
	adds r1, r0, #0
	adds r4, r6, #0
	adds r4, #0x6c
	b _08002EC8
_08002EB8:
	adds r4, r6, #0
	adds r4, #0x6c
	ldr r0, _08002EDC @ =0x08251B2C
	bl FUN_08230860
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
_08002EC8:
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r7, r4, #0
	cmp r0, #0
	bne _08002EE0
	movs r0, #1
	rsbs r0, r0, #0
	b _08002F32
	.align 2, 0
_08002EDC: .4byte 0x08251B2C
_08002EE0:
	movs r5, #0
	ldr r0, [r6, #0x24]
	cmp r5, r0
	bge _08002F14
	movs r0, #0x88
	adds r0, r0, r6
	mov r8, r0
_08002EEE:
	movs r0, #0x2c
	muls r0, r5, r0
	mov r1, r8
	ldr r4, [r1]
	adds r4, r4, r0
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #1
	bl AuxSprite_Setup
	ldr r0, [r4, #0x18]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r4, #0x18]
	adds r5, #1
	ldr r0, [r6, #0x24]
	cmp r5, r0
	blt _08002EEE
_08002F14:
	movs r0, #2
	movs r1, #0xc
	movs r2, #0x2c
	bl Video_SetBLDCNTDirect
	movs r0, #0
	movs r1, #0x10
	bl Video_SetBLDALPHADirect
	ldr r0, _08002F3C @ =0x00007BE3
	adds r1, r6, #0
	movs r2, #0
	bl Registry_Add
	movs r0, #0
_08002F32:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08002F3C: .4byte 0x00007BE3
