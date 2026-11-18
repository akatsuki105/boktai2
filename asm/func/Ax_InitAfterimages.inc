	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r6, [r0]
	movs r2, #0
	mov sb, r2
	movs r0, #0xed
	lsls r0, r0, #3
	adds r5, r6, r0
	ldr r1, _0819EEFC @ =0x0000073C
	adds r4, r6, r1
	movs r7, #0
	movs r2, #3
	mov r8, r2
_0819EE94:
	adds r0, r5, #0
	ldr r1, _0819EF00 @ =0x00005291
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl AuxSprite_Add
	movs r0, #0xf7
	strh r0, [r4, #0x32]
	ldr r1, _0819EF04 @ =0x00000774
	adds r0, r6, r1
	adds r0, r0, r7
	ldr r2, _0819EF08 @ =0x000008BC
	adds r1, r6, r2
	str r1, [r0]
	ldr r0, _0819EF0C @ =0x0000922E
	ldr r1, _0819EF10 @ =0x00003F72
	bl GetFile
	ldr r2, _0819EF14 @ =0x00000794
	adds r1, r6, r2
	adds r1, r1, r7
	str r0, [r1]
	ldr r0, _0819EF18 @ =0x00000201
	str r0, [r4]
	mov r0, sb
	strh r0, [r5, #0x30]
	adds r5, #0x60
	adds r4, #0x60
	adds r7, #0x60
	movs r1, #1
	rsbs r1, r1, #0
	add r8, r1
	mov r2, r8
	cmp r2, #0
	bge _0819EE94
	movs r1, #0
	ldr r2, _0819EF1C @ =0x00000E44
	adds r0, r6, r2
	strh r1, [r0]
	ldr r0, _0819EF20 @ =0x00000E46
	adds r1, r6, r0
	movs r0, #2
	strh r0, [r1]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0819EEFC: .4byte 0x0000073C
_0819EF00: .4byte 0x00005291
_0819EF04: .4byte 0x00000774
_0819EF08: .4byte 0x000008BC
_0819EF0C: .4byte 0x0000922E
_0819EF10: .4byte 0x00003F72
_0819EF14: .4byte 0x00000794
_0819EF18: .4byte 0x00000201
_0819EF1C: .4byte 0x00000E44
_0819EF20: .4byte 0x00000E46
