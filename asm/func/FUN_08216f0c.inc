	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _08216F34 @ =0x0000166C
	adds r0, r0, r7
	mov sb, r0
	ldr r1, _08216F38 @ =0x00001FE2
	adds r3, r7, r1
	movs r0, #0
	ldrsh r2, [r3, r0]
	cmp r2, #1
	beq _08216FD4
	cmp r2, #1
	bgt _08216F3C
	cmp r2, #0
	beq _08216F44
	b _08217204
	.align 2, 0
_08216F34: .4byte 0x0000166C
_08216F38: .4byte 0x00001FE2
_08216F3C:
	cmp r2, #2
	bne _08216F42
	b _08217176
_08216F42:
	b _08217204
_08216F44:
	movs r0, #0x10
	ldr r1, [r7, #0x44]
	ands r0, r1
	cmp r0, #0
	bne _08216F78
	ldr r1, _08216F68 @ =0x00001FE4
	adds r0, r7, r1
	strh r2, [r0]
	ldr r0, _08216F6C @ =0x41414141
	str r0, [sp]
	ldr r3, _08216F70 @ =0x00001FC4
	adds r1, r7, r3
	ldr r2, _08216F74 @ =0x05000006
	mov r0, sp
	bl CpuSet
	b _08216FAA
	.align 2, 0
_08216F68: .4byte 0x00001FE4
_08216F6C: .4byte 0x41414141
_08216F70: .4byte 0x00001FC4
_08216F74: .4byte 0x05000006
_08216F78:
	movs r0, #0x11
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x44]
	adds r0, r7, #0
	movs r1, #1
	bl FUN_08216cf4
	movs r0, #0x20
	ldr r1, [r7, #0x44]
	ands r0, r1
	cmp r0, #0
	beq _08216FA2
	movs r0, #0x21
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r7, #0x44]
	ldr r0, _08216FC8 @ =0x00001FDC
	adds r1, r7, r0
	movs r0, #0x17
	strh r0, [r1]
_08216FA2:
	ldr r3, _08216FCC @ =0x00001FE4
	adds r1, r7, r3
	movs r0, #0x41
	strh r0, [r1]
_08216FAA:
	adds r0, r7, #0
	bl FUN_08216a90
	adds r0, r7, #0
	bl FUN_08216bdc
	movs r0, #0
	str r0, [r7, #0x68]
	str r0, [r7, #0x6c]
	ldr r1, _08216FD0 @ =0x00000976
	add r1, sb
	movs r0, #1
	strh r0, [r1]
	b _08217204
	.align 2, 0
_08216FC8: .4byte 0x00001FDC
_08216FCC: .4byte 0x00001FE4
_08216FD0: .4byte 0x00000976
_08216FD4:
	ldr r4, _08216FF8 @ =0x030044E0
	ldrh r1, [r4, #2]
	movs r5, #2
	adds r0, r5, #0
	ands r0, r1
	cmp r0, #0
	beq _08216FFC
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r7, #0
	bl FUN_08216ea8
	cmp r0, #0
	bne _08216FF4
	b _08217204
_08216FF4:
	movs r0, #3
	b _0821721C
	.align 2, 0
_08216FF8: .4byte 0x030044E0
_08216FFC:
	ands r2, r1
	lsls r0, r2, #0x10
	cmp r0, #0
	beq _0821702C
	ldr r0, _08217028 @ =0x00001FE4
	adds r4, r7, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0x41
	beq _08217058
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r3, #0
	ldrsh r1, [r4, r3]
	adds r0, r7, #0
	bl FUN_08216e60
	cmp r0, #0
	bne _08217026
	b _08217204
_08217026:
	b _08217046
	.align 2, 0
_08217028: .4byte 0x00001FE4
_0821702C:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0821705C
	ldr r0, _08217054 @ =0x00001FE4
	adds r4, r7, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0x41
	beq _08217058
	movs r0, #0xdc
	bl PlaySound_082406e0
_08217046:
	movs r0, #0x41
	strh r0, [r4]
	adds r0, r7, #0
	bl FUN_08216a90
	b _08217204
	.align 2, 0
_08217054: .4byte 0x00001FE4
_08217058:
	strh r5, [r3]
	b _08217204
_0821705C:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0821707C
	ldr r3, _08217078 @ =0x00001FDC
	adds r1, r7, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _08217098
	subs r0, r2, #1
	b _08217096
	.align 2, 0
_08217078: .4byte 0x00001FDC
_0821707C:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _082170AC
	ldr r0, _082170A8 @ =0x00001FDC
	adds r1, r7, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0x16
	bgt _08217098
	adds r0, r2, #1
_08217096:
	strh r0, [r1]
_08217098:
	adds r0, r7, #0
	bl FUN_08216bdc
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _08217204
	.align 2, 0
_082170A8: .4byte 0x00001FDC
_082170AC:
	movs r6, #0
	movs r5, #0
	movs r0, #0x20
	mov r8, r0
	ands r0, r1
	cmp r0, #0
	bne _082170F0
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _082170C6
	movs r6, #2
	b _082170F6
_082170C6:
	ldrh r1, [r4]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _082170F4
	ldr r0, [r7, #0x68]
	adds r0, #1
	str r0, [r7, #0x68]
	cmp r0, #0xe
	ble _082170F6
	movs r1, #5
	bl Mod
	cmp r0, #0
	bne _082170F6
	ldrh r1, [r4]
	mov r0, r8
	ands r0, r1
	movs r6, #2
	cmp r0, #0
	beq _082170F6
_082170F0:
	movs r6, #1
	b _082170F6
_082170F4:
	str r5, [r7, #0x68]
_082170F6:
	ldr r4, _08217114 @ =0x030044E0
	ldrh r1, [r4, #2]
	movs r3, #0x40
	mov r8, r3
	mov r0, r8
	ands r0, r1
	cmp r0, #0
	bne _08217142
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08217118
	movs r5, #2
	b _08217148
	.align 2, 0
_08217114: .4byte 0x030044E0
_08217118:
	ldrh r0, [r4]
	movs r1, #0xc0
	ands r1, r0
	cmp r1, #0
	beq _08217146
	ldr r0, [r7, #0x6c]
	adds r0, #1
	str r0, [r7, #0x6c]
	cmp r0, #0xe
	ble _08217148
	movs r1, #5
	bl Mod
	cmp r0, #0
	bne _08217148
	ldrh r1, [r4]
	mov r0, r8
	ands r0, r1
	movs r5, #2
	cmp r0, #0
	beq _08217148
_08217142:
	movs r5, #1
	b _08217148
_08217146:
	str r1, [r7, #0x6c]
_08217148:
	cmp r6, #1
	bne _08217154
	adds r0, r7, #0
	bl FUN_0821722c
	b _0821715E
_08217154:
	cmp r6, #2
	bne _0821715E
	adds r0, r7, #0
	bl FUN_08217440
_0821715E:
	cmp r5, #1
	bne _0821716A
	adds r0, r7, #0
	bl FUN_08217648
	b _08217204
_0821716A:
	cmp r5, #2
	bne _08217204
	adds r0, r7, #0
	bl FUN_0821785c
	b _08217204
_08217176:
	movs r1, #0x10
	ldr r0, [r7, #0x44]
	orrs r0, r1
	str r0, [r7, #0x44]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_08216cf4
	ldr r1, _082171E4 @ =0x000017A4
	adds r0, r7, r1
	ldr r3, _082171E8 @ =0x00001BA4
	adds r6, r7, r3
	adds r1, r6, #0
	bl FUN_08216968
	ldr r1, _082171EC @ =0x00001794
	adds r0, r7, r1
	ldr r5, [r0]
	ldr r3, _082171F0 @ =0x00001798
	adds r0, r7, r3
	ldr r4, [r0]
	bl FUN_0823cd38
	adds r3, r0, #0
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08011584
	adds r4, r0, #0
	bl FUN_0823cd38
	movs r2, #0
_082171B8:
	ldrb r1, [r0]
	cmp r1, #0
	bne _082171C4
	cmp r2, #8
	bgt _082171C4
	strb r1, [r0, #1]
_082171C4:
	adds r0, #1
	adds r2, #1
	cmp r2, #9
	ble _082171B8
	cmp r4, #0
	bne _082171F8
	ldr r0, _082171F4 @ =0x00000296
	bl PlaySound_082406e0
	movs r1, #0x20
	ldr r0, [r7, #0x44]
	orrs r0, r1
	str r0, [r7, #0x44]
	movs r0, #1
	b _0821721C
	.align 2, 0
_082171E4: .4byte 0x000017A4
_082171E8: .4byte 0x00001BA4
_082171EC: .4byte 0x00001794
_082171F0: .4byte 0x00001798
_082171F4: .4byte 0x00000296
_082171F8:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	movs r0, #2
	b _0821721C
_08217204:
	mov r0, sb
	adds r0, #0xc0
	adds r4, r7, #0
	adds r4, #0x18
	adds r1, r4, #0
	bl FUN_082372cc
	mov r0, sb
	adds r1, r4, #0
	bl FUN_082372cc
	movs r0, #0
_0821721C:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
