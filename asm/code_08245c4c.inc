	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08245c4c
FUN_08245c4c: @ 0x08245C4C
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	movs r2, #0
	movs r6, #1
	ldr r1, [r0, #0x18]
	adds r3, r0, #0
	adds r3, #0x24
	movs r5, #0xb3
	lsls r5, r5, #2
_08245C5E:
	adds r0, r6, #0
	lsls r0, r2
	ands r0, r1
	cmp r0, #0
	bne _08245C6E
	str r2, [r4]
	adds r0, r3, #0
	b _08245C78
_08245C6E:
	adds r3, r3, r5
	adds r2, #1
	cmp r2, #7
	ble _08245C5E
	movs r0, #0
_08245C78:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08245c80
FUN_08245c80: @ 0x08245C80
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r7, r1, #0
	adds r4, r2, #0
	adds r6, r4, #0
	adds r0, #0x42
	ldrb r0, [r0]
	strb r0, [r4, #9]
	movs r1, #7
	ldr r0, [r5, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _08245CEA
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08236524
	adds r0, r7, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #2
	mov r8, r0
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	cmp r7, #0
	beq _08245CD0
	ldr r0, _08245CCC @ =0x00000229
	bl PlaySound_082406e0
	movs r0, #1
	strb r0, [r4, #1]
	strb r0, [r4]
	movs r0, #0
	strh r0, [r4, #6]
	b _08245CEA
	.align 2, 0
_08245CCC: .4byte 0x00000229
_08245CD0:
	movs r1, #0x7f
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _08245CEA
	ldr r0, _08245CF4 @ =0x0000022A
	bl PlaySound_082406e0
	mov r0, r8
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	strh r7, [r6, #6]
_08245CEA:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08245CF4: .4byte 0x0000022A

	thumb_func_start FUN_08245cf8
FUN_08245cf8: @ 0x08245CF8
	bx lr
	.align 2, 0

	thumb_func_start FUN_08245cfc
FUN_08245cfc: @ 0x08245CFC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	str r0, [sp, #0x20]
	mov sb, r1
	movs r1, #0
	movs r2, #0
	mov r0, sb
	strb r1, [r0, #1]
	movs r0, #1
	mov r3, sb
	strb r0, [r3]
	strh r2, [r3, #6]
	strb r1, [r3, #9]
	strh r2, [r3, #0xa]
	movs r4, #0xac
	lsls r4, r4, #2
	add r4, sb
	ldr r1, _08245E44 @ =0x00008202
	adds r0, r4, #0
	bl FUN_0822b16c
	ldr r1, _08245E48 @ =0x0000015F
	adds r0, r4, #0
	bl FUN_0822b20c
	movs r4, #0x92
	lsls r4, r4, #1
	add r4, sb
	movs r5, #0
	add r6, sp, #0x10
	add r0, sp, #0x18
	mov sl, r0
	movs r7, #0
_08245D46:
	adds r0, r4, #0
	movs r1, #0xac
	lsls r1, r1, #2
	add r1, sb
	movs r2, #1
	bl FUN_0822a4b0
	movs r0, #8
	subs r0, r0, r5
	strh r0, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #7]
	adds r1, r4, #0
	adds r1, #0x1c
	str r7, [sp, #0xc]
	add r0, sp, #0xc
	ldr r2, _08245E4C @ =0x05000002
	bl CpuSet
	adds r5, #1
	adds r4, #0x2c
	cmp r5, #8
	ble _08245D46
	mov r7, sb
	adds r7, #0xd4
	ldr r2, _08245E50 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	movs r4, #0x20
	orrs r0, r4
	ldr r1, _08245E54 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [r6, #4]
	ands r0, r2
	orrs r0, r4
	str r0, [r6, #4]
	movs r5, #0
	str r5, [sp, #0x18]
	mov r1, sl
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _08245E58 @ =0x00004005
	movs r3, #0x10
	str r3, [sp]
	str r6, [sp, #4]
	str r1, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r0, #0x14
	add r0, sb
	mov r8, r0
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08245E5C @ =FUN_08245c80
	adds r0, r7, #0
	mov r2, sb
	bl FUN_0823651c
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	adds r0, r7, #0
	bl FUN_08236400
	subs r7, #0x50
	add r0, sp, #0x10
	strh r4, [r0]
	movs r0, #0x64
	strh r0, [r6, #2]
	strh r4, [r6, #4]
	add r0, sp, #0x18
	strh r5, [r0]
	mov r1, sl
	strh r5, [r1, #2]
	strh r5, [r1, #4]
	ldr r2, _08245E60 @ =0x00002001
	movs r3, #0x10
	str r3, [sp]
	str r6, [sp, #4]
	str r1, [sp, #8]
	adds r0, r7, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r7, #0
	mov r1, r8
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _08245E64 @ =FUN_08245cf8
	adds r0, r7, #0
	mov r2, sb
	bl FUN_0823651c
	ldr r0, [sp, #0x20]
	ldrh r1, [r0, #0x1c]
	str r5, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r2, #0x1e
	movs r3, #0x10
	bl FUN_082364f8
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08245E44: .4byte 0x00008202
_08245E48: .4byte 0x0000015F
_08245E4C: .4byte 0x05000002
_08245E50: .4byte 0xFFFF0000
_08245E54: .4byte 0x0000FFFF
_08245E58: .4byte 0x00004005
_08245E5C: .4byte FUN_08245c80
_08245E60: .4byte 0x00002001
_08245E64: .4byte FUN_08245cf8

	thumb_func_start FUN_08245e68
FUN_08245e68: @ 0x08245E68
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r6, r1, #0
	mov r8, r2
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #8
_08245E7C:
	adds r0, r4, #0
	bl FUN_0822a4e0
	subs r5, #1
	adds r4, #0x2c
	cmp r5, #0
	bge _08245E7C
	adds r3, r6, #0
	adds r3, #0xd4
	ldrh r2, [r3, #6]
	movs r1, #4
	orrs r1, r2
	strh r1, [r3, #6]
	movs r2, #1
	mov r1, r8
	lsls r2, r1
	ldr r1, [r7, #0x18]
	bics r1, r2
	str r1, [r7, #0x18]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08245eac
FUN_08245eac: @ 0x08245EAC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrh r1, [r4, #6]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _08245EC8
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r0, [r4, #0x14]
	ldr r1, [r4, #0x18]
	str r0, [r2]
	str r1, [r2, #4]
_08245EC8:
	ldrb r0, [r4, #8]
	subs r2, r0, #1
	cmp r2, #0
	bge _08245ED2
	movs r2, #8
_08245ED2:
	movs r1, #0xa8
	lsls r1, r1, #1
	adds r3, r4, r1
	movs r5, #7
_08245EDA:
	lsls r0, r2, #3
	adds r0, r0, r4
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	subs r2, #1
	cmp r2, #0
	bge _08245EEE
	movs r2, #8
_08245EEE:
	subs r5, #1
	adds r3, #0x2c
	cmp r5, #0
	bge _08245EDA
	ldrh r0, [r4, #6]
	movs r3, #1
	ands r3, r0
	cmp r3, #0
	bne _08245F24
	ldrb r2, [r4, #8]
	lsls r2, r2, #3
	adds r2, r2, r4
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldrb r0, [r4, #8]
	adds r0, #1
	strb r0, [r4, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bls _08245F24
	strb r3, [r4, #8]
_08245F24:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08245f2c
FUN_08245f2c: @ 0x08245F2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov ip, r0
	ldrb r0, [r0, #8]
	subs r6, r0, #1
	cmp r6, #0
	bge _08245F44
	movs r6, #8
_08245F44:
	movs r7, #0
	ldr r0, _08245F78 @ =0x085B0A08
	mov sl, r0
	movs r1, #0xff
	mov sb, r1
	mov r8, sp
	movs r3, #0xa0
	lsls r3, r3, #1
	add r3, ip
_08245F56:
	lsls r0, r7, #1
	mov r2, ip
	ldrh r2, [r2, #6]
	cmp r0, r2
	ble _08245F7C
	lsls r0, r6, #3
	add r0, ip
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [r3]
	str r1, [r3, #4]
	subs r6, #1
	cmp r6, #0
	bge _08245FEE
	movs r6, #8
	b _08245FEE
	.align 2, 0
_08245F78: .4byte 0x085B0A08
_08245F7C:
	mov r1, ip
	adds r1, #0x70
	adds r1, r1, r7
	mov r0, ip
	adds r0, #0x79
	adds r0, r0, r7
	mov r4, sp
	ldrb r2, [r1]
	ldrb r5, [r0]
	adds r0, r2, #0
	adds r0, #0x40
	mov r1, sb
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08245FA8
	asrs r1, r0, #0xc
	b _08245FAE
_08245FA8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08245FAE:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	mov r0, sb
	ands r2, r0
	lsls r0, r2, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08245FCA
	asrs r0, r0, #0xc
	b _08245FD0
_08245FCA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08245FD0:
	strh r0, [r4, #4]
	mov r2, r8
	ldrh r0, [r2]
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r2, [r3, #2]
	adds r0, r0, r2
	strh r0, [r3, #2]
	mov r1, r8
	ldrh r0, [r1, #4]
	ldrh r2, [r3, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
_08245FEE:
	adds r7, #1
	adds r3, #0x2c
	cmp r7, #8
	ble _08245F56
	mov r1, ip
	ldrh r0, [r1, #6]
	movs r3, #1
	ands r3, r0
	cmp r3, #0
	bne _08246028
	ldrb r2, [r1, #8]
	lsls r2, r2, #3
	add r2, ip
	movs r0, #0xa0
	lsls r0, r0, #1
	add r0, ip
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	mov r2, ip
	ldrb r0, [r2, #8]
	adds r0, #1
	strb r0, [r2, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bls _08246028
	strb r3, [r2, #8]
_08246028:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08246038
FUN_08246038: @ 0x08246038
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r2, [r4, #0x6c]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #0x14
	ldrsh r1, [r4, r3]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r3, #0x18
	ldrsh r2, [r4, r3]
	subs r1, r1, r2
	bl FUN_0823785c
	lsls r0, r0, #8
	strh r0, [r4, #0xa]
	ldrh r1, [r4, #0xe]
	lsls r2, r1, #1
	adds r2, r2, r1
	ldrh r1, [r4, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	asrs r5, r0, #0x10
	lsls r2, r2, #0x12
	asrs r1, r2, #0x10
	rsbs r0, r1, #0
	cmp r5, r0
	bge _0824607A
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	b _08246080
_0824607A:
	cmp r5, r1
	ble _08246080
	lsrs r3, r2, #0x10
_08246080:
	ldrh r0, [r4, #0xc]
	adds r0, r0, r3
	strh r0, [r4, #0xc]
	lsrs r0, r0, #8
	strb r0, [r4, #9]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08246090
FUN_08246090: @ 0x08246090
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r6, r1, #0
	ldrb r0, [r6]
	cmp r0, #0
	beq _082460B6
	movs r0, #0
	strb r0, [r6]
	adds r2, r6, #0
	adds r2, #0xd4
	subs r0, #5
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	ldrb r0, [r6, #9]
	lsls r0, r0, #8
	strh r0, [r6, #0xc]
	movs r0, #0x40
	strh r0, [r6, #0xe]
_082460B6:
	ldrh r0, [r6, #0xe]
	cmp r0, #0
	beq _082460C0
	subs r0, #1
	strh r0, [r6, #0xe]
_082460C0:
	adds r0, r6, #0
	bl FUN_08246038
	mov r3, sp
	ldrb r4, [r6, #9]
	ldrh r5, [r6, #0x10]
	ldr r2, _082460E8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _082460EC
	asrs r1, r0, #0xc
	b _082460F2
	.align 2, 0
_082460E8: .4byte 0x085B0A08
_082460EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_082460F2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0824610C @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08246110
	asrs r0, r0, #0xc
	b _08246116
	.align 2, 0
_0824610C: .4byte 0x085B0A08
_08246110:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08246116:
	strh r0, [r3, #4]
	adds r4, r6, #0
	adds r4, #0x14
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r2, [r6, #0x14]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r4, #2]
	adds r0, r0, r2
	strh r0, [r4, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r4, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	adds r5, r6, #0
	adds r5, #0x84
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r6, #0
	adds r0, #0xd4
	adds r1, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	bl FUN_08236400
	adds r0, r6, #0
	bl FUN_08245eac
	ldrh r0, [r6, #6]
	cmp r0, #0x95
	bls _08246170
	movs r0, #3
	strb r0, [r6, #1]
	movs r0, #1
	strb r0, [r6]
	movs r0, #0
	b _08246172
_08246170:
	adds r0, #1
_08246172:
	strh r0, [r6, #6]
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0824617c
FUN_0824617c: @ 0x0824617C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r1, #0
	ldrb r0, [r5]
	cmp r0, #0
	beq _08246206
	movs r0, #0
	strb r0, [r5]
	adds r2, r5, #0
	adds r2, #0xd4
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	adds r4, r5, #0
	adds r4, #0x14
	ldr r0, [r5, #0x14]
	ldr r1, [r5, #0x18]
	str r0, [r5, #0x64]
	str r1, [r5, #0x68]
	bl FUN_080230c4
	str r0, [r5, #0x6c]
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r3, #0x14
	ldrsh r1, [r5, r3]
	subs r2, r2, r1
	movs r6, #4
	ldrsh r1, [r0, r6]
	movs r3, #4
	ldrsh r0, [r4, r3]
	subs r1, r1, r0
	adds r0, r2, #0
	bl FUN_0823785c
	adds r3, r0, #0
	ldr r2, _082461E8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _082461EC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r6, _082461F0 @ =0x0203B400
	adds r0, r0, r6
	ldrb r0, [r0]
	cmp r0, #0x7f
	bgt _082461F4
	adds r0, r3, #0
	subs r0, #0x40
	b _082461F8
	.align 2, 0
_082461E8: .4byte 0x030046B8
_082461EC: .4byte 0x000003FF
_082461F0: .4byte 0x0203B400
_082461F4:
	adds r0, r3, #0
	adds r0, #0x40
_082461F8:
	strb r0, [r5, #9]
	adds r0, r5, #0
	adds r0, #0x84
	movs r1, #1
	strh r1, [r0, #0xa]
	adds r0, #0x50
	strh r1, [r0, #0xa]
_08246206:
	adds r4, r5, #0
	adds r4, #0x14
	adds r1, r5, #0
	adds r1, #0x64
	ldr r2, [r5, #0x6c]
	ldrh r3, [r5, #6]
	movs r0, #5
	str r0, [sp]
	adds r0, r4, #0
	bl FUN_08237970
	ldr r3, _08246258 @ =0x085B0A08
	ldrh r0, [r5, #6]
	lsls r0, r0, #2
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r6, #0
	ldrsh r1, [r0, r6]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #5
	mov r8, r0
	add r7, sp, #4
	ldrb r0, [r5, #9]
	mov ip, r0
	adds r0, #0x40
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	adds r6, r4, #0
	cmp r0, #0
	blt _0824625C
	asrs r1, r0, #0xc
	b _08246262
	.align 2, 0
_08246258: .4byte 0x085B0A08
_0824625C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08246262:
	movs r0, #0
	strh r1, [r7]
	strh r0, [r7, #2]
	ldr r1, _08246284 @ =0x085B0A08
	mov r3, ip
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _08246288
	asrs r0, r0, #0xc
	b _0824628E
	.align 2, 0
_08246284: .4byte 0x085B0A08
_08246288:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0824628E:
	strh r0, [r7, #4]
	add r1, sp, #4
	adds r0, r1, #0
	ldrh r0, [r0]
	ldrh r3, [r5, #0x14]
	adds r0, r0, r3
	strh r0, [r5, #0x14]
	ldrh r0, [r1, #2]
	ldrh r2, [r6, #2]
	adds r0, r0, r2
	strh r0, [r6, #2]
	ldrh r0, [r1, #4]
	ldrh r3, [r6, #4]
	adds r0, r0, r3
	strh r0, [r6, #4]
	adds r4, r5, #0
	adds r4, #0x84
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r5, #0
	adds r0, #0xd4
	adds r1, r6, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	adds r0, r5, #0
	bl FUN_08245eac
	ldrh r0, [r5, #6]
	cmp r0, #0x1f
	bls _082462E4
	movs r0, #2
	strb r0, [r5, #1]
	movs r0, #1
	strb r0, [r5]
	movs r0, #0
	b _082462E6
_082462E4:
	adds r0, #1
_082462E6:
	strh r0, [r5, #6]
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_082462f4
FUN_082462f4: @ 0x082462F4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	adds r4, r1, #0
	mov sl, r2
	ldrb r0, [r4]
	cmp r0, #0
	beq _08246392
	movs r0, #0
	strb r0, [r4]
	adds r2, r4, #0
	adds r2, #0xd4
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r3, r4, r0
	movs r1, #0xa0
	lsls r1, r1, #1
	adds r2, r4, r1
	movs r5, #0
	ldrsh r0, [r2, r5]
	movs r5, #0
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r5, #4
	ldrsh r2, [r3, r5]
	subs r1, r1, r2
	bl FUN_0823785c
	strb r0, [r4, #9]
	movs r3, #0
	movs r0, #0x70
	adds r0, r0, r4
	mov r8, r0
	movs r1, #0x79
	adds r1, r1, r4
	mov ip, r1
	ldr r7, _082463AC @ =0x0203B400
	ldr r5, _082463B0 @ =0x030046B8
	ldr r6, _082463B4 @ =0x000003FF
_08246354:
	ldr r0, [r5]
	adds r0, #1
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r0, [r0]
	mov r1, r8
	adds r2, r1, r3
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0xf0
	ldrb r1, [r4, #9]
	adds r0, r0, r1
	strb r0, [r2]
	ldr r0, [r5]
	adds r0, #1
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	adds r0, r0, r7
	ldrh r1, [r0]
	mov r0, ip
	adds r2, r0, r3
	movs r0, #0xf
	ands r1, r0
	adds r1, #0x18
	strb r1, [r2]
	adds r3, #1
	cmp r3, #8
	ble _08246354
_08246392:
	adds r0, r4, #0
	bl FUN_08245f2c
	ldrh r0, [r4, #6]
	cmp r0, #0x1d
	bls _082463B8
	mov r0, sb
	adds r1, r4, #0
	mov r2, sl
	bl FUN_08245e68
	b _082463BC
	.align 2, 0
_082463AC: .4byte 0x0203B400
_082463B0: .4byte 0x030046B8
_082463B4: .4byte 0x000003FF
_082463B8:
	adds r0, #1
	strh r0, [r4, #6]
_082463BC:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082463CC:
	.byte 0x70, 0xB5, 0x05, 0x1C
	.byte 0x0C, 0x1C, 0x16, 0x1C, 0x20, 0x78, 0x00, 0x28, 0x07, 0xD0, 0x00, 0x20, 0x20, 0x70, 0x22, 0x1C
	.byte 0xD4, 0x32, 0xD1, 0x88, 0x04, 0x20, 0x08, 0x43, 0xD0, 0x80, 0x20, 0x1C, 0xFF, 0xF7, 0x5E, 0xFD
	.byte 0xE0, 0x88, 0x1D, 0x28, 0x05, 0xD9, 0x28, 0x1C, 0x21, 0x1C, 0x32, 0x1C, 0xFF, 0xF7, 0x34, 0xFD
	.byte 0x01, 0xE0, 0x01, 0x30, 0xE0, 0x80, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_0824640c
FUN_0824640c: @ 0x0824640C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x24
	movs r5, #0
	ldr r7, _0824644C @ =0x08DBD800
_08246418:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _08246436
	ldrb r0, [r4, #1]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
_08246436:
	adds r5, #1
	movs r0, #0xb3
	lsls r0, r0, #2
	adds r4, r4, r0
	cmp r5, #7
	ble _08246418
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0824644C: .4byte 0x08DBD800

	thumb_func_start FUN_08246450
FUN_08246450: @ 0x08246450
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x24
	movs r5, #0
_0824645A:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _08246470
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_08245e68
_08246470:
	adds r0, r4, #0
	adds r0, #0xd4
	bl FUN_08236424
	adds r5, #1
	movs r0, #0xb3
	lsls r0, r0, #2
	adds r4, r4, r0
	cmp r5, #7
	ble _0824645A
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0824648c
FUN_0824648c: @ 0x0824648C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	strh r1, [r6, #0x1c]
	adds r5, r6, #0
	adds r5, #0x24
	movs r4, #0
_08246498:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08245cfc
	adds r4, #1
	movs r0, #0xb3
	lsls r0, r0, #2
	adds r5, r5, r0
	cmp r4, #7
	ble _08246498
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082464b8
FUN_082464b8: @ 0x082464B8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _082464E8 @ =0x00001684
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _082464F4
	ldr r1, _082464EC @ =FUN_0824640c
	ldr r2, _082464F0 @ =FUN_08246450
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0824648c
	cmp r0, #0
	bge _082464F4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _082464F6
	.align 2, 0
_082464E8: .4byte 0x00001684
_082464EC: .4byte FUN_0824640c
_082464F0: .4byte FUN_08246450
_082464F4:
	adds r0, r4, #0
_082464F6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_082464fc
FUN_082464fc: @ 0x082464FC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sb, r0
	adds r7, r1, #0
	adds r6, r2, #0
	adds r4, r3, #0
	add r1, sp, #8
	bl FUN_08245c4c
	adds r5, r0, #0
	cmp r5, #0
	bne _08246522
	movs r0, #1
	rsbs r0, r0, #0
	b _0824660C
_08246522:
	movs r1, #0
	strb r1, [r5, #1]
	movs r0, #1
	strb r0, [r5]
	movs r2, #0
	strh r1, [r5, #6]
	strb r4, [r5, #9]
	lsls r0, r4, #8
	strh r0, [r5, #0xa]
	strh r0, [r5, #0xc]
	ldr r0, [sp, #0x2c]
	strh r0, [r5, #0x10]
	ldr r0, [sp, #0x30]
	strb r0, [r5, #2]
	movs r0, #0x40
	strh r0, [r5, #0xe]
	strb r2, [r5, #8]
	str r6, [r5, #0x6c]
	ldr r0, [r7]
	ldr r1, [r7, #4]
	str r0, [r5, #0x14]
	str r1, [r5, #0x18]
	movs r0, #0x92
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r6, #0
	movs r1, #0x84
	adds r1, r1, r5
	mov r8, r1
	movs r2, #0x14
	adds r2, r2, r5
	mov sl, r2
	adds r7, r5, #0
	adds r7, #0xd4
_08246566:
	lsls r2, r6, #3
	adds r2, r2, r5
	ldr r0, [r5, #0x14]
	ldr r1, [r5, #0x18]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r5, #0x14]
	ldr r1, [r5, #0x18]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0822a340
	adds r6, #1
	adds r4, #0x2c
	cmp r6, #8
	ble _08246566
	movs r1, #0xac
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r5, #2]
	ldr r2, _0824661C @ =0x0000015F
	adds r1, r1, r2
	bl FUN_0822b20c
	mov r0, r8
	mov r1, sl
	movs r2, #0
	bl FUN_082364c4
	adds r0, r7, #0
	mov r1, sl
	movs r2, #0
	bl FUN_082364c4
	ldrh r1, [r7, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r7, #6]
	movs r0, #0x10
	mov r1, r8
	strh r0, [r1, #0xa]
	strh r0, [r7, #0xa]
	ldr r4, _08246620 @ =0x08DBD7D0
	ldrb r0, [r5, #2]
	lsls r0, r0, #3
	adds r0, r0, r4
	ldr r0, [r0]
	mov r2, sb
	ldrh r1, [r2, #0x1c]
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	mov r0, r8
	movs r2, #0x1e
	movs r3, #0x10
	bl FUN_082364f8
	ldrb r0, [r5, #2]
	lsls r0, r0, #3
	adds r1, r0, r4
	ldr r2, [r1]
	adds r4, #4
	adds r0, r0, r4
	ldr r3, [r0]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_08236514
	ldr r0, [sp, #8]
	movs r1, #1
	lsls r1, r0
	mov r2, sb
	ldr r0, [r2, #0x18]
	orrs r0, r1
	str r0, [r2, #0x18]
	movs r0, #0
_0824660C:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0824661C: .4byte 0x0000015F
_08246620: .4byte 0x08DBD7D0

	thumb_func_start FUN_08246624
FUN_08246624: @ 0x08246624
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r3, r5, #0
	adds r3, #0x24
	movs r4, #0
	movs r6, #1
	movs r1, #3
	mov ip, r1
	movs r7, #0xb3
	lsls r7, r7, #2
_08246638:
	adds r2, r6, #0
	lsls r2, r4
	ldr r1, [r5, #0x18]
	ands r1, r2
	cmp r1, #0
	beq _08246652
	ldrb r1, [r3, #1]
	cmp r1, #0
	bne _08246652
	mov r2, ip
	strb r2, [r3, #1]
	strb r6, [r3]
	strh r1, [r3, #6]
_08246652:
	adds r4, #1
	adds r3, r3, r7
	cmp r4, #7
	ble _08246638
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08246660
FUN_08246660: @ 0x08246660
	ldr r1, _08246668 @ =0x030026B0
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08246668: .4byte 0x030026B0

	thumb_func_start FUN_0824666c
FUN_0824666c: @ 0x0824666C
	bx lr
	.align 2, 0

	thumb_func_start FUN_08246670
FUN_08246670: @ 0x08246670
	push {r4, lr}
	adds r3, r0, #0
	ldrb r2, [r1]
	cmp r2, #0
	beq _08246680
	movs r0, #1
	rsbs r0, r0, #0
	b _082466A2
_08246680:
	movs r4, #0x98
	lsls r4, r4, #1
	adds r0, r1, r4
	str r2, [r0]
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r2, [r3, #0x20]
	str r2, [r0]
	cmp r2, #0
	beq _0824669A
	adds r0, r2, r4
	str r1, [r0]
_0824669A:
	str r1, [r3, #0x20]
	movs r0, #1
	strb r0, [r1]
	movs r0, #0
_082466A2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_082466a8
FUN_082466a8: @ 0x082466A8
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r2, #0x98
	lsls r2, r2, #1
	adds r0, r1, r2
	ldr r3, [r0]
	movs r4, #0x9a
	lsls r4, r4, #1
	adds r0, r1, r4
	ldr r2, [r0]
	ldrb r0, [r1]
	cmp r0, #0
	bne _082466C8
	movs r0, #1
	rsbs r0, r0, #0
	b _082466E4
_082466C8:
	cmp r3, #0
	beq _082466D2
	adds r0, r3, r4
	str r2, [r0]
	b _082466D4
_082466D2:
	str r2, [r5, #0x20]
_082466D4:
	cmp r2, #0
	beq _082466E0
	movs r4, #0x98
	lsls r4, r4, #1
	adds r0, r2, r4
	str r3, [r0]
_082466E0:
	movs r0, #0
	strb r0, [r1]
_082466E4:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082466ec
FUN_082466ec: @ 0x082466EC
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r2, #0
	movs r6, #0
	movs r5, #2
	adds r1, r3, #0
	adds r1, #0xc
	movs r4, #0xa
_082466FC:
	ldrb r0, [r1]
	cmp r0, #1
	bne _0824670A
	strb r5, [r1]
	strb r4, [r1, #1]
	strh r6, [r1, #2]
	b _08246718
_0824670A:
	adds r1, #0x48
	adds r2, #1
	cmp r2, #3
	ble _082466FC
	movs r0, #0
	cmp r0, #0
	beq _0824671E
_08246718:
	ldrb r0, [r3, #3]
	subs r0, #1
	strb r0, [r3, #3]
_0824671E:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08246728
FUN_08246728: @ 0x08246728
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	mov ip, r3
	movs r5, #0
	movs r0, #0
	movs r3, #0
	adds r1, r4, #0
	adds r1, #0xc
_0824673E:
	ldrb r2, [r1]
	cmp r2, #1
	bne _0824676E
	ldr r0, [r1, #0x10]
	orrs r0, r2
	str r0, [r1, #0x10]
	strb r3, [r1]
	movs r0, #0xa
	strb r0, [r1, #1]
	strh r3, [r1, #2]
	movs r5, #1
	ldrb r1, [r4, #1]
	ldr r0, [sp, #0x20]
	str r0, [sp]
	ldr r0, [sp, #0x24]
	str r0, [sp, #4]
	ldr r0, [sp, #0x28]
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r2, r7, #0
	mov r3, ip
	bl FUN_08014730
	b _08246776
_0824676E:
	adds r1, #0x48
	adds r0, #1
	cmp r0, #3
	ble _0824673E
_08246776:
	cmp r5, #0
	beq _08246786
	ldrb r0, [r4, #3]
	subs r0, #1
	strb r0, [r4, #3]
	ldrb r0, [r4, #2]
	subs r0, #1
	strb r0, [r4, #2]
_08246786:
	movs r0, #0
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08246790
FUN_08246790: @ 0x08246790
	push {r4, r5, r6, lr}
	adds r2, r0, #0
	movs r1, #0
	strb r1, [r2, #2]
	strb r1, [r2, #3]
	strb r1, [r2, #1]
	movs r1, #0x96
	lsls r1, r1, #1
	adds r3, r2, r1
	ldr r1, _082467CC @ =FUN_0824666c
	str r1, [r3]
	movs r4, #0
	movs r6, #0xa
	movs r5, #1
	adds r2, #0xc
	movs r3, #3
_082467B0:
	strb r4, [r2]
	strh r4, [r2, #2]
	strb r6, [r2, #1]
	ldr r1, [r2, #0x10]
	orrs r1, r5
	str r1, [r2, #0x10]
	adds r2, #0x48
	subs r3, #1
	cmp r3, #0
	bge _082467B0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_082467CC: .4byte FUN_0824666c

	thumb_func_start FUN_082467d0
FUN_082467d0: @ 0x082467D0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	mov ip, r2
	mov r8, r3
	ldr r0, _082467F4 @ =0x030026B0
	ldr r7, [r0]
	cmp r7, #0
	beq _08246808
	cmp r1, #0
	bne _082467F8
	adds r0, r5, #0
	bl FUN_08246790
	b _082469A8
	.align 2, 0
_082467F4: .4byte 0x030026B0
_082467F8:
	ldrb r2, [r5, #2]
	cmp r2, #0
	beq _08246804
	ldrb r0, [r5, #1]
	cmp r0, r1
	bne _08246808
_08246804:
	cmp r2, #3
	bls _0824680E
_08246808:
	movs r0, #1
	rsbs r0, r0, #0
	b _082469AA
_0824680E:
	ldrb r0, [r5, #1]
	cmp r0, r1
	beq _0824686A
	strb r1, [r5, #1]
	ldrb r0, [r5, #1]
	cmp r0, #1
	beq _08246840
	cmp r0, #1
	bgt _08246826
	cmp r0, #0
	beq _08246830
	b _0824686A
_08246826:
	cmp r0, #2
	beq _08246850
	cmp r0, #3
	beq _08246860
	b _0824686A
_08246830:
	movs r0, #0x96
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _0824683C @ =FUN_0824666c
	b _08246868
	.align 2, 0
_0824683C: .4byte FUN_0824666c
_08246840:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, _0824684C @ =FUN_082470a8
	b _08246868
	.align 2, 0
_0824684C: .4byte FUN_082470a8
_08246850:
	movs r0, #0x96
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, _0824685C @ =FUN_08247194
	b _08246868
	.align 2, 0
_0824685C: .4byte FUN_08247194
_08246860:
	movs r2, #0x96
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r0, _08246890 @ =FUN_08247280
_08246868:
	str r0, [r1]
_0824686A:
	movs r0, #0
	mov sb, r0
	add r6, sp, #4
	ldr r2, [r5, #8]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08246894
	asrs r0, r0, #8
	b _0824689A
	.align 2, 0
_08246890: .4byte FUN_08247280
_08246894:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0824689A:
	strh r0, [r6]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _082468AC
	asrs r0, r0, #8
	b _082468B2
_082468AC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_082468B2:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08246924
	asrs r0, r0, #8
	b _0824692A
_082468C6:
	movs r0, #1
	strb r0, [r4]
	strh r6, [r4, #2]
	mov r2, ip
	strh r2, [r4, #4]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #8]
	str r1, [r4, #0xc]
	add r1, sp, #4
	ldrh r0, [r4, #8]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x28]
	add r2, sp, #4
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #0xa]
	adds r0, r0, r1
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0xc]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r4, #0x2c]
	ldr r0, [r4, #0x10]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x10]
	adds r0, r4, #0
	adds r0, #0x38
	ldr r1, [r7, #0x1c]
	ldr r3, _08246920 @ =0x08DBD810
	ldrb r2, [r5, #1]
	lsls r2, r2, #1
	adds r2, r2, r3
	ldrh r2, [r2]
	str r6, [sp]
	movs r3, #0
	bl FUN_08236fac
	movs r0, #1
	mov sb, r0
	b _0824695C
	.align 2, 0
_08246920: .4byte 0x08DBD810
_08246924:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0824692A:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0824697C @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	movs r2, #0
	adds r4, r5, #0
	adds r4, #0xc
_0824694E:
	ldrb r6, [r4]
	cmp r6, #0
	beq _082468C6
	adds r4, #0x48
	adds r2, #1
	cmp r2, #3
	ble _0824694E
_0824695C:
	ldrb r0, [r5, #1]
	cmp r0, #2
	bne _08246980
	movs r3, #0x80
	lsls r3, r3, #2
	adds r1, r5, #0
	adds r1, #0x1c
	movs r2, #3
_0824696C:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x48
	subs r2, #1
	cmp r2, #0
	bge _0824696C
	b _08246996
	.align 2, 0
_0824697C: .4byte 0x030047C8
_08246980:
	ldr r3, _082469B8 @ =0xFFFFFDFF
	adds r1, r5, #0
	adds r1, #0x1c
	movs r2, #3
_08246988:
	ldr r0, [r1]
	ands r0, r3
	str r0, [r1]
	adds r1, #0x48
	subs r2, #1
	cmp r2, #0
	bge _08246988
_08246996:
	mov r2, sb
	cmp r2, #0
	beq _082469A8
	ldrb r0, [r5, #2]
	adds r0, #1
	strb r0, [r5, #2]
	ldrb r0, [r5, #3]
	adds r0, #1
	strb r0, [r5, #3]
_082469A8:
	movs r0, #0
_082469AA:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_082469B8: .4byte 0xFFFFFDFF

	thumb_func_start FUN_082469bc
FUN_082469bc: @ 0x082469BC
	movs r1, #0
	strb r1, [r0]
	strh r1, [r0, #2]
	movs r1, #0xa
	strb r1, [r0, #1]
	ldr r1, [r0, #0x10]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #0x10]
	bx lr

	thumb_func_start FUN_082469d0
FUN_082469d0: @ 0x082469D0
	bx lr
	.align 2, 0

	thumb_func_start FUN_082469d4
FUN_082469d4: @ 0x082469D4
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	mov ip, r2
	mov r5, ip
	adds r5, #0x10
	ldr r3, [r0, #0x18]
	mov r4, ip
	adds r4, #0x38
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r2, #0x38]
	adds r6, r1, r0
	ldrh r2, [r6]
	lsrs r2, r2, #6
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r5, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08246A24
	mov r3, ip
	ldr r0, [r3, #0x10]
	movs r1, #4
	orrs r0, r1
	str r0, [r3, #0x10]
	b _08246A32
_08246A24:
	mov r1, ip
	ldr r0, [r1, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2, #0x10]
_08246A32:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08246A54
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08246A5C
_08246A54:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08246A5C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08246A94 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08246ABE
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08246A98
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08246A8C
	ldrb r0, [r4, #5]
_08246A8C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08246AA8
	.align 2, 0
_08246A94: .4byte 0x0000FFFF
_08246A98:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08246AA8
	strh r1, [r4, #8]
_08246AA8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
_08246ABE:
	mov r1, ip
	adds r1, #0x40
	ldrh r0, [r1]
	cmp r0, #5
	bne _08246ACC
	movs r0, #0
	strh r0, [r1]
_08246ACC:
	mov r3, ip
	ldrh r1, [r3, #4]
	movs r2, #4
	ldrsh r0, [r3, r2]
	cmp r0, #0
	ble _08246AF4
	subs r0, r1, #1
	strh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bne _08246AF4
	movs r0, #2
	strb r0, [r3]
	movs r0, #0xa
	strb r0, [r3, #1]
	strh r1, [r3, #2]
	ldrb r0, [r7, #3]
	subs r0, #1
	strb r0, [r7, #3]
_08246AF4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08246afc
FUN_08246afc: @ 0x08246AFC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	adds r7, r2, #0
	adds r5, r7, #0
	adds r5, #0x10
	ldr r3, [r0, #0x18]
	adds r4, r7, #0
	adds r4, #0x38
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r7, #0x38]
	adds r6, r1, r0
	ldrh r2, [r6]
	lsrs r2, r2, #6
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r5, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08246B4C
	ldr r0, [r7, #0x10]
	movs r1, #4
	orrs r0, r1
	b _08246B54
_08246B4C:
	ldr r0, [r7, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08246B54:
	str r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08246B78
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08246B80
_08246B78:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08246B80:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08246BB8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08246BF0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08246BC2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08246BBC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _08246BD8
	.align 2, 0
_08246BB8: .4byte 0x0000FFFF
_08246BBC:
	subs r0, #1
	strh r0, [r4, #8]
	b _08246BD6
_08246BC2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08246BD6
	strh r1, [r4, #8]
	movs r2, #1
	b _08246BD8
_08246BD6:
	movs r2, #0
_08246BD8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	b _08246BF2
_08246BF0:
	movs r2, #0
_08246BF2:
	cmp r2, #0
	beq _08246C04
	adds r0, r7, #0
	bl FUN_082469bc
	mov r1, r8
	ldrb r0, [r1, #2]
	subs r0, #1
	strb r0, [r1, #2]
_08246C04:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08246c10
FUN_08246c10: @ 0x08246C10
	bx lr
	.align 2, 0

	thumb_func_start FUN_08246c14
FUN_08246c14: @ 0x08246C14
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	mov ip, r2
	mov r5, ip
	adds r5, #0x10
	ldr r3, [r0, #0x18]
	mov r4, ip
	adds r4, #0x38
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r2, #0x38]
	adds r6, r1, r0
	ldrh r2, [r6]
	lsrs r2, r2, #6
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r5, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08246C64
	mov r3, ip
	ldr r0, [r3, #0x10]
	movs r1, #4
	orrs r0, r1
	str r0, [r3, #0x10]
	b _08246C72
_08246C64:
	mov r1, ip
	ldr r0, [r1, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2, #0x10]
_08246C72:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08246C94
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08246C9C
_08246C94:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08246C9C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08246CD4 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08246CFE
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08246CD8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08246CCC
	ldrb r0, [r4, #5]
_08246CCC:
	subs r0, #1
	strh r0, [r4, #8]
	b _08246CE8
	.align 2, 0
_08246CD4: .4byte 0x0000FFFF
_08246CD8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08246CE8
	strh r1, [r4, #8]
_08246CE8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
_08246CFE:
	mov r3, ip
	ldrh r1, [r3, #4]
	movs r2, #4
	ldrsh r0, [r3, r2]
	cmp r0, #0
	ble _08246D26
	subs r0, r1, #1
	strh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bne _08246D26
	movs r0, #2
	strb r0, [r3]
	movs r0, #0xa
	strb r0, [r3, #1]
	strh r1, [r3, #2]
	ldrb r0, [r7, #3]
	subs r0, #1
	strb r0, [r7, #3]
_08246D26:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08246d2c
FUN_08246d2c: @ 0x08246D2C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	adds r5, r2, #0
	adds r6, r5, #0
	adds r6, #0x10
	ldr r3, [r0, #0x18]
	adds r4, r5, #0
	adds r4, #0x38
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x38]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r6, #8]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08246D7C
	ldr r0, [r5, #0x10]
	movs r1, #4
	orrs r0, r1
	b _08246D84
_08246D7C:
	ldr r0, [r5, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08246D84:
	str r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08246DA8
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08246DB0
_08246DA8:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08246DB0:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08246DE8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08246E12
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08246DEC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08246DE0
	ldrb r0, [r4, #5]
_08246DE0:
	subs r0, #1
	strh r0, [r4, #8]
	b _08246DFC
	.align 2, 0
_08246DE8: .4byte 0x0000FFFF
_08246DEC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08246DFC
	strh r1, [r4, #8]
_08246DFC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
_08246E12:
	ldrh r0, [r5, #2]
	ldrb r1, [r5, #1]
	cmp r0, r1
	bne _08246E32
	ldr r0, [r5, #0x10]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x10]
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _08246E2C
	subs r0, #1
	strb r0, [r5, #1]
_08246E2C:
	movs r0, #0
	strh r0, [r5, #2]
	b _08246E3C
_08246E32:
	ldr r0, [r5, #0x10]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x10]
_08246E3C:
	ldrb r0, [r5, #1]
	cmp r0, #0
	bne _08246E50
	adds r0, r5, #0
	bl FUN_082469bc
	mov r2, r8
	ldrb r0, [r2, #2]
	subs r0, #1
	strb r0, [r2, #2]
_08246E50:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08246e5c
FUN_08246e5c: @ 0x08246E5C
	bx lr
	.align 2, 0

	thumb_func_start FUN_08246e60
FUN_08246e60: @ 0x08246E60
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	mov ip, r2
	mov r5, ip
	adds r5, #0x10
	ldr r3, [r0, #0x18]
	mov r4, ip
	adds r4, #0x38
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r2, #0x38]
	adds r6, r1, r0
	ldrh r2, [r6]
	lsrs r2, r2, #6
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r5, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08246EB0
	mov r3, ip
	ldr r0, [r3, #0x10]
	movs r1, #4
	orrs r0, r1
	str r0, [r3, #0x10]
	b _08246EBE
_08246EB0:
	mov r1, ip
	ldr r0, [r1, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
	str r0, [r2, #0x10]
_08246EBE:
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08246EE0
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08246EE8
_08246EE0:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08246EE8:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _08246F20 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _08246F4A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08246F24
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08246F18
	ldrb r0, [r4, #5]
_08246F18:
	subs r0, #1
	strh r0, [r4, #8]
	b _08246F34
	.align 2, 0
_08246F20: .4byte 0x0000FFFF
_08246F24:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08246F34
	strh r1, [r4, #8]
_08246F34:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
_08246F4A:
	mov r3, ip
	ldrh r1, [r3, #4]
	movs r2, #4
	ldrsh r0, [r3, r2]
	cmp r0, #0
	ble _08246F72
	subs r0, r1, #1
	strh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x10
	cmp r1, #0
	bne _08246F72
	movs r0, #2
	strb r0, [r3]
	movs r0, #0xa
	strb r0, [r3, #1]
	strh r1, [r3, #2]
	ldrb r0, [r7, #3]
	subs r0, #1
	strb r0, [r7, #3]
_08246F72:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08246f78
FUN_08246f78: @ 0x08246F78
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r1
	adds r5, r2, #0
	adds r6, r5, #0
	adds r6, #0x10
	ldr r3, [r0, #0x18]
	adds r4, r5, #0
	adds r4, #0x38
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x38]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r6, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r6, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r6, #8]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08246FC8
	ldr r0, [r5, #0x10]
	movs r1, #4
	orrs r0, r1
	b _08246FD0
_08246FC8:
	ldr r0, [r5, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08246FD0:
	str r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08246FF4
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _08246FFC
_08246FF4:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08246FFC:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08247034 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0824705E
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _08247038
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _0824702C
	ldrb r0, [r4, #5]
_0824702C:
	subs r0, #1
	strh r0, [r4, #8]
	b _08247048
	.align 2, 0
_08247034: .4byte 0x0000FFFF
_08247038:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _08247048
	strh r1, [r4, #8]
_08247048:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
_0824705E:
	ldrh r0, [r5, #2]
	ldrb r1, [r5, #1]
	cmp r0, r1
	bne _0824707E
	ldr r0, [r5, #0x10]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x10]
	ldrb r0, [r5, #1]
	cmp r0, #0
	beq _08247078
	subs r0, #1
	strb r0, [r5, #1]
_08247078:
	movs r0, #0
	strh r0, [r5, #2]
	b _08247088
_0824707E:
	ldr r0, [r5, #0x10]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x10]
_08247088:
	ldrb r0, [r5, #1]
	cmp r0, #0
	bne _0824709C
	adds r0, r5, #0
	bl FUN_082469bc
	mov r2, r8
	ldrb r0, [r2, #2]
	subs r0, #1
	strb r0, [r2, #2]
_0824709C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_082470a8
FUN_082470a8: @ 0x082470A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	mov r8, r1
	mov r5, sp
	ldr r2, [r1, #8]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _082470D8
	asrs r0, r0, #8
	b _082470DE
_082470D8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_082470DE:
	strh r0, [r5]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _082470F0
	asrs r0, r0, #8
	b _082470F6
_082470F0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_082470F6:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0824710A
	asrs r0, r0, #8
	b _08247110
_0824710A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08247110:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0824718C @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	ldr r1, _08247190 @ =0x08DBD818
	mov sb, r1
	mov r6, sp
	mov r5, r8
	adds r5, #0xc
	adds r4, r5, #0
	movs r7, #3
_0824713C:
	ldrb r0, [r4]
	lsls r0, r0, #2
	add r0, sb
	ldr r3, [r0]
	mov r0, sl
	mov r1, r8
	adds r2, r5, #0
	bl _call_via_r3
	ldrb r0, [r4]
	cmp r0, #0
	beq _08247172
	ldrh r0, [r4, #8]
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r4, #0x28]
	ldrh r0, [r6, #2]
	ldrh r1, [r4, #0xa]
	adds r0, r0, r1
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0xc]
	ldrh r1, [r6, #4]
	adds r0, r0, r1
	strh r0, [r4, #0x2c]
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
_08247172:
	adds r4, #0x48
	adds r5, #0x48
	subs r7, #1
	cmp r7, #0
	bge _0824713C
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0824718C: .4byte 0x030047C8
_08247190: .4byte 0x08DBD818

	thumb_func_start FUN_08247194
FUN_08247194: @ 0x08247194
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	mov r8, r1
	mov r5, sp
	ldr r2, [r1, #8]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _082471C4
	asrs r0, r0, #8
	b _082471CA
_082471C4:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_082471CA:
	strh r0, [r5]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _082471DC
	asrs r0, r0, #8
	b _082471E2
_082471DC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_082471E2:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _082471F6
	asrs r0, r0, #8
	b _082471FC
_082471F6:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_082471FC:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08247278 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	ldr r1, _0824727C @ =0x08DBD824
	mov sb, r1
	mov r6, sp
	mov r5, r8
	adds r5, #0xc
	adds r4, r5, #0
	movs r7, #3
_08247228:
	ldrb r0, [r4]
	lsls r0, r0, #2
	add r0, sb
	ldr r3, [r0]
	mov r0, sl
	mov r1, r8
	adds r2, r5, #0
	bl _call_via_r3
	ldrb r0, [r4]
	cmp r0, #0
	beq _0824725E
	ldrh r0, [r4, #8]
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r4, #0x28]
	ldrh r0, [r6, #2]
	ldrh r1, [r4, #0xa]
	adds r0, r0, r1
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0xc]
	ldrh r1, [r6, #4]
	adds r0, r0, r1
	strh r0, [r4, #0x2c]
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
_0824725E:
	adds r4, #0x48
	adds r5, #0x48
	subs r7, #1
	cmp r7, #0
	bge _08247228
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08247278: .4byte 0x030047C8
_0824727C: .4byte 0x08DBD824

	thumb_func_start FUN_08247280
FUN_08247280: @ 0x08247280
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	mov r8, r1
	mov r5, sp
	ldr r2, [r1, #8]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x11
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	subs r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _082472B0
	asrs r0, r0, #8
	b _082472B6
_082472B0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_082472B6:
	strh r0, [r5]
	adds r1, r4, r3
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _082472C8
	asrs r0, r0, #8
	b _082472CE
_082472C8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_082472CE:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r2, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _082472E2
	asrs r0, r0, #8
	b _082472E8
_082472E2:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_082472E8:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08247364 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	ldr r1, _08247368 @ =0x08DBD830
	mov sb, r1
	mov r6, sp
	mov r5, r8
	adds r5, #0xc
	adds r4, r5, #0
	movs r7, #3
_08247314:
	ldrb r0, [r4]
	lsls r0, r0, #2
	add r0, sb
	ldr r3, [r0]
	mov r0, sl
	mov r1, r8
	adds r2, r5, #0
	bl _call_via_r3
	ldrb r0, [r4]
	cmp r0, #0
	beq _0824734A
	ldrh r0, [r4, #8]
	ldrh r1, [r6]
	adds r0, r0, r1
	strh r0, [r4, #0x28]
	ldrh r0, [r6, #2]
	ldrh r1, [r4, #0xa]
	adds r0, r0, r1
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0xc]
	ldrh r1, [r6, #4]
	adds r0, r0, r1
	strh r0, [r4, #0x2c]
	ldrh r0, [r4, #2]
	adds r0, #1
	strh r0, [r4, #2]
_0824734A:
	adds r4, #0x48
	adds r5, #0x48
	subs r7, #1
	cmp r7, #0
	bge _08247314
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08247364: .4byte 0x030047C8
_08247368: .4byte 0x08DBD830

	thumb_func_start FUN_0824736c
FUN_0824736c: @ 0x0824736C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r4, [r5, #0x20]
	cmp r4, #0
	beq _08247392
_08247376:
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl _call_via_r2
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r4, [r0]
	cmp r4, #0
	bne _08247376
_08247392:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0824739C:
	.byte 0x01, 0x49, 0x00, 0x20
	.byte 0x08, 0x60, 0x70, 0x47, 0xB0, 0x26, 0x00, 0x03

	thumb_func_start FUN_082473a8
FUN_082473a8: @ 0x082473A8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _082473D0 @ =0x030026B0
	str r4, [r0]
	movs r0, #0
	str r0, [r4, #0x20]
	ldr r0, _082473D4 @ =0x00001C1A
	bl FUN_0822b10c
	str r0, [r4, #0x18]
	ldr r0, _082473D8 @ =0x0000922E
	ldr r1, _082473DC @ =0x0000D1B8
	bl FUN_082310cc
	str r0, [r4, #0x1c]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_082473D0: .4byte 0x030026B0
_082473D4: .4byte 0x00001C1A
_082473D8: .4byte 0x0000922E
_082473DC: .4byte 0x0000D1B8

	thumb_func_start FUN_082473e0
FUN_082473e0: @ 0x082473E0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08247418 @ =0x030026B0
	ldr r0, [r0]
	cmp r0, #0
	bne _08247426
	movs r0, #9
	movs r1, #0x24
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08247424
	ldr r1, _0824741C @ =FUN_0824736c
	ldr r2, _08247420 @ =0x0824739D
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_082473a8
	cmp r0, #0
	bge _08247424
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08247426
	.align 2, 0
_08247418: .4byte 0x030026B0
_0824741C: .4byte FUN_0824736c
_08247420: .4byte 0x0824739D
_08247424:
	adds r0, r4, #0
_08247426:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0824742c
FUN_0824742c: @ 0x0824742C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r7, r3, #0
	ldr r0, _08247460 @ =0x030026B0
	ldr r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _08247464
	movs r0, #0
	movs r1, #0
	bl FUN_082473e0
	mov sl, r0
	cmp r0, #0
	bne _08247464
	movs r0, #1
	rsbs r0, r0, #0
	b _082474EC
	.align 2, 0
_08247460: .4byte 0x030026B0
_08247464:
	movs r0, #0
	strb r0, [r6]
	str r4, [r6, #8]
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r5, [r6, #1]
	strb r7, [r6, #4]
	ldr r0, [sp, #0x24]
	strb r0, [r6, #5]
	movs r0, #0x96
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _082474FC @ =FUN_0824666c
	str r0, [r1]
	movs r7, #0
	movs r1, #0x44
	adds r1, r1, r6
	mov r8, r1
	adds r5, r6, #0
	adds r5, #0x1c
	adds r4, r6, #0
	adds r4, #0xc
	movs r0, #3
	mov sb, r0
_08247494:
	strb r7, [r4]
	strh r7, [r4, #2]
	strh r7, [r4, #8]
	strh r7, [r4, #0xa]
	strh r7, [r4, #0xc]
	ldr r1, _08247500 @ =0x030026B0
	ldr r0, [r1]
	ldr r1, [r0, #0x18]
	adds r0, r5, #0
	movs r2, #0x11
	bl FUN_0822d9f0
	adds r0, r5, #0
	movs r1, #8
	rsbs r1, r1, #0
	adds r2, r1, #0
	bl FUN_0822dad4
	movs r0, #2
	strb r0, [r4, #0x1f]
	ldr r1, _08247500 @ =0x030026B0
	ldr r0, [r1]
	ldr r1, [r0, #0x1c]
	str r7, [sp]
	mov r0, r8
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	movs r0, #0x48
	add r8, r0
	adds r5, #0x48
	adds r4, #0x48
	movs r1, #1
	rsbs r1, r1, #0
	add sb, r1
	mov r0, sb
	cmp r0, #0
	bge _08247494
	mov r0, sl
	adds r1, r6, #0
	bl FUN_08246670
	movs r0, #0
_082474EC:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_082474FC: .4byte FUN_0824666c
_08247500: .4byte 0x030026B0

	thumb_func_start FUN_08247504
FUN_08247504: @ 0x08247504
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x1c
	movs r5, #3
_0824750E:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x48
	subs r5, #1
	cmp r5, #0
	bge _0824750E
	ldr r0, _08247534 @ =0x030026B0
	ldr r0, [r0]
	cmp r0, #0
	beq _0824752A
	adds r1, r6, #0
	bl FUN_082466a8
_0824752A:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08247534: .4byte 0x030026B0

	thumb_func_start FUN_08247538
FUN_08247538: @ 0x08247538
	push {r4, r5, r6, lr}
	ldr r2, _082475B4 @ =0x030026C0
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	movs r4, #1
	orrs r0, r4
	str r0, [r2]
	ldr r0, _082475B8 @ =0x030026B4
	movs r2, #0
	str r2, [r0]
	ldr r0, _082475BC @ =0x030026B8
	str r2, [r0]
	ldr r0, _082475C0 @ =0x030057B8
	str r2, [r0]
	ldr r1, _082475C4 @ =0x030057CC
	ldr r0, _082475C8 @ =0x00003128
	str r0, [r1]
	ldr r0, _082475CC @ =0x030057C0
	str r4, [r0]
	ldr r1, _082475D0 @ =0x030057B0
	movs r0, #0xff
	str r0, [r1]
	ldr r1, _082475D4 @ =0x030057C4
	movs r0, #4
	str r0, [r1]
	ldr r1, _082475D8 @ =0x030057C8
	subs r0, #5
	str r0, [r1]
	ldr r5, _082475DC @ =0x04000208
	strh r2, [r5]
	ldr r3, _082475E0 @ =0x04000200
	ldrh r6, [r3]
	strh r2, [r3]
	ldr r0, _082475E4 @ =0x0400010C
	strh r2, [r0]
	ldr r1, _082475E8 @ =0x0400010E
	movs r0, #0xc0
	strh r0, [r1]
	ldr r1, _082475EC @ =0x03002CB0
	ldr r0, _082475F0 @ =FUN_08247650
	str r0, [r1, #8]
	ldr r1, _082475F4 @ =0x030057B4
	ldr r0, _082475F8 @ =0x080000C4
	ldrh r0, [r0]
	str r0, [r1]
	ldr r1, _082475FC @ =0x080000C6
	movs r0, #7
	strh r0, [r1]
	ldr r0, _08247600 @ =0x080000C8
	strh r4, [r0]
	movs r0, #0x40
	orrs r0, r6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	strh r0, [r3]
	strh r4, [r5]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_082475B4: .4byte 0x030026C0
_082475B8: .4byte 0x030026B4
_082475BC: .4byte 0x030026B8
_082475C0: .4byte 0x030057B8
_082475C4: .4byte 0x030057CC
_082475C8: .4byte 0x00003128
_082475CC: .4byte 0x030057C0
_082475D0: .4byte 0x030057B0
_082475D4: .4byte 0x030057C4
_082475D8: .4byte 0x030057C8
_082475DC: .4byte 0x04000208
_082475E0: .4byte 0x04000200
_082475E4: .4byte 0x0400010C
_082475E8: .4byte 0x0400010E
_082475EC: .4byte 0x03002CB0
_082475F0: .4byte FUN_08247650
_082475F4: .4byte 0x030057B4
_082475F8: .4byte 0x080000C4
_082475FC: .4byte 0x080000C6
_08247600: .4byte 0x080000C8

	thumb_func_start FUN_08247604
FUN_08247604: @ 0x08247604
	push {r4, r5, lr}
	ldr r5, _08247634 @ =0x04000208
	movs r2, #0
	strh r2, [r5]
	ldr r3, _08247638 @ =0x04000200
	ldrh r4, [r3]
	strh r2, [r3]
	ldr r0, _0824763C @ =0x0400010E
	strh r2, [r0]
	subs r0, #2
	strh r2, [r0]
	ldr r1, _08247640 @ =0x03002CB0
	ldr r0, _08247644 @ =FUN_0822a18c
	str r0, [r1, #8]
	ldr r0, _08247648 @ =0x080000C8
	strh r2, [r0]
	ldr r0, _0824764C @ =0x0000FFBF
	ands r0, r4
	strh r0, [r3]
	movs r0, #1
	strh r0, [r5]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08247634: .4byte 0x04000208
_08247638: .4byte 0x04000200
_0824763C: .4byte 0x0400010E
_08247640: .4byte 0x03002CB0
_08247644: .4byte FUN_0822a18c
_08247648: .4byte 0x080000C8
_0824764C: .4byte 0x0000FFBF

	thumb_func_start FUN_08247650
FUN_08247650: @ 0x08247650
	push {r4, r5, r6, lr}
	ldr r0, _0824768C @ =0x080000C4
	ldrh r3, [r0]
	ldr r2, _08247690 @ =0x030026C0
	ldr r4, [r2]
	strh r4, [r0]
	ldr r1, _08247694 @ =0x0400010C
	ldr r0, _08247698 @ =0x030057CC
	ldr r0, [r0]
	rsbs r0, r0, #0
	strh r0, [r1]
	movs r5, #8
	ands r5, r3
	ldr r0, _0824769C @ =0x030057BC
	str r5, [r0]
	ldr r0, _082476A0 @ =0x030057B8
	ldr r0, [r0]
	cmp r0, #0
	beq _08247722
	ldr r0, _082476A4 @ =0x030026B4
	ldr r1, [r0]
	adds r3, r0, #0
	cmp r1, #1
	beq _082476F0
	cmp r1, #1
	bgt _082476AC
	cmp r1, #0
	beq _082476B8
	ldr r6, _082476A8 @ =0x030026B8
	b _0824771C
	.align 2, 0
_0824768C: .4byte 0x080000C4
_08247690: .4byte 0x030026C0
_08247694: .4byte 0x0400010C
_08247698: .4byte 0x030057CC
_0824769C: .4byte 0x030057BC
_082476A0: .4byte 0x030057B8
_082476A4: .4byte 0x030026B4
_082476A8: .4byte 0x030026B8
_082476AC:
	ldr r6, _082476B4 @ =0x030026B8
	cmp r1, #2
	beq _08247706
	b _0824771C
	.align 2, 0
_082476B4: .4byte 0x030026B8
_082476B8:
	ldr r0, _082476C8 @ =0x030026B8
	ldr r1, [r0]
	adds r6, r0, #0
	cmp r1, #9
	bgt _082476CC
	movs r0, #2
	orrs r4, r0
	b _082476D2
	.align 2, 0
_082476C8: .4byte 0x030026B8
_082476CC:
	movs r0, #3
	rsbs r0, r0, #0
	ands r4, r0
_082476D2:
	str r4, [r2]
	ldr r0, [r6]
	cmp r0, #0x14
	ble _0824771C
	cmp r5, #0
	bne _0824771C
	ldr r0, [r3]
	adds r0, #1
	str r0, [r3]
	str r5, [r6]
	ldr r0, _082476EC @ =0x030026BC
	str r5, [r0]
	b _0824771C
	.align 2, 0
_082476EC: .4byte 0x030026BC
_082476F0:
	ldr r6, _08247728 @ =0x030026B8
	cmp r5, #0
	beq _08247702
	ldr r0, _0824772C @ =0x030057C8
	ldr r1, [r6]
	asrs r1, r1, #1
	str r1, [r0]
	movs r0, #2
	str r0, [r3]
_08247702:
	ldr r0, _08247730 @ =0x030026BC
	str r5, [r0]
_08247706:
	ldr r0, [r2]
	movs r1, #1
	eors r0, r1
	str r0, [r2]
	ldr r1, [r6]
	ldr r0, _08247734 @ =0x000001FF
	cmp r1, r0
	ble _0824771C
	movs r0, #0
	str r0, [r3]
	str r0, [r6]
_0824771C:
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
_08247722:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08247728: .4byte 0x030026B8
_0824772C: .4byte 0x030057C8
_08247730: .4byte 0x030026BC
_08247734: .4byte 0x000001FF

	thumb_func_start FUN_08247738
FUN_08247738: @ 0x08247738
	push {lr}
	ldr r1, _08247750 @ =0x030057B4
	movs r0, #0
	str r0, [r1]
	ldr r1, _08247754 @ =0x030026C4
	movs r0, #1
	str r0, [r1]
	bl FUN_08247538
	pop {r0}
	bx r0
	.align 2, 0
_08247750: .4byte 0x030057B4
_08247754: .4byte 0x030026C4

	thumb_func_start FUN_08247758
FUN_08247758: @ 0x08247758
	push {lr}
	ldr r1, _08247770 @ =0x030026C4
	ldr r0, [r1]
	cmp r0, #0
	beq _0824776A
	movs r0, #0
	str r0, [r1]
	bl FUN_08247604
_0824776A:
	pop {r0}
	bx r0
	.align 2, 0
_08247770: .4byte 0x030026C4

	thumb_func_start FUN_08247774
FUN_08247774: @ 0x08247774
	push {lr}
	ldr r0, _082477A0 @ =0x030026C4
	ldr r0, [r0]
	cmp r0, #0
	bne _08247782
	bl FUN_08247738
_08247782:
	ldr r1, _082477A4 @ =0x030057B8
	movs r0, #1
	str r0, [r1]
	ldr r0, _082477A8 @ =0x030026B4
	movs r1, #0
	str r1, [r0]
	ldr r0, _082477AC @ =0x030026B8
	str r1, [r0]
	ldr r1, _082477B0 @ =0x030057C8
	movs r0, #1
	rsbs r0, r0, #0
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_082477A0: .4byte 0x030026C4
_082477A4: .4byte 0x030057B8
_082477A8: .4byte 0x030026B4
_082477AC: .4byte 0x030026B8
_082477B0: .4byte 0x030057C8

	thumb_func_start FUN_082477b4
FUN_082477b4: @ 0x082477B4
	push {lr}
	ldr r0, _082477D4 @ =0x030026C4
	ldr r0, [r0]
	cmp r0, #1
	bne _082477C2
	bl FUN_08247758
_082477C2:
	ldr r1, _082477D8 @ =0x030057B8
	movs r0, #0
	str r0, [r1]
	ldr r1, _082477DC @ =0x030057C8
	subs r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_082477D4: .4byte 0x030026C4
_082477D8: .4byte 0x030057B8
_082477DC: .4byte 0x030057C8

	thumb_func_start FUN_082477e0
FUN_082477e0: @ 0x082477E0
	push {lr}
	ldr r0, _082477F0 @ =0x030057B8
	ldr r0, [r0]
	cmp r0, #0
	beq _082477F8
	ldr r0, _082477F4 @ =0x030057C8
	ldr r0, [r0]
	b _082477FC
	.align 2, 0
_082477F0: .4byte 0x030057B8
_082477F4: .4byte 0x030057C8
_082477F8:
	movs r0, #1
	rsbs r0, r0, #0
_082477FC:
	pop {r1}
	bx r1
_08247800:
	.byte 0x01, 0x48, 0x00, 0x68, 0x70, 0x47, 0x00, 0x00, 0xC4, 0x26, 0x00, 0x03, 0x01, 0x48, 0x00, 0x68
	.byte 0x70, 0x47, 0x00, 0x00, 0xB4, 0x26, 0x00, 0x03, 0x01, 0x48, 0x00, 0x68, 0x70, 0x47, 0x00, 0x00
	.byte 0xB8, 0x26, 0x00, 0x03

	thumb_func_start FUN_08247824
FUN_08247824: @ 0x08247824
	push {r4, lr}
	adds r3, r0, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	cmp r2, #1
	bne _08247860
	adds r2, r3, #0
	adds r2, #0xe8
	str r2, [r1]
	ldr r1, _0824784C @ =0x040000D4
	ldr r0, _08247850 @ =0x08248360
	str r0, [r1]
	str r2, [r1, #4]
	ldr r0, _08247854 @ =0x800004B0
	str r0, [r1, #8]
	ldr r0, [r1, #8]
	ldr r1, _08247858 @ =0x030057D0
	ldr r2, _0824785C @ =0x00000A48
	adds r0, r3, r2
	b _0824786A
	.align 2, 0
_0824784C: .4byte 0x040000D4
_08247850: .4byte 0x08248360
_08247854: .4byte 0x800004B0
_08247858: .4byte 0x030057D0
_0824785C: .4byte 0x00000A48
_08247860:
	ldr r0, _082478E4 @ =0x08248360
	str r0, [r1]
	ldr r1, _082478E8 @ =0x030057D0
	adds r0, r3, #0
	adds r0, #0xe8
_0824786A:
	str r0, [r1]
	adds r2, r1, #0
	ldr r1, [r2]
	str r3, [r1, #0x28]
	adds r0, r3, #0
	adds r0, #0x74
	str r0, [r1, #0x24]
	ldrb r0, [r1, #0x14]
	movs r4, #0
	movs r0, #1
	strb r0, [r1, #0x14]
	ldr r0, [r2]
	str r4, [r0]
	strb r4, [r0, #4]
	ldr r0, [r2]
	strb r4, [r0, #5]
	ldr r0, [r2]
	strb r4, [r0, #7]
	ldr r0, [r2]
	strb r4, [r0, #8]
	ldr r0, [r2]
	strb r4, [r0, #9]
	ldr r0, [r2]
	str r4, [r0, #0xc]
	ldrb r1, [r0, #0x10]
	strb r4, [r0, #0x10]
	ldr r0, [r2]
	ldrh r1, [r0, #0x12]
	movs r1, #0
	strh r4, [r0, #0x12]
	strb r1, [r0, #0x15]
	ldr r0, [r2]
	adds r0, #0x2c
	ldrb r2, [r0]
	strb r1, [r0]
	ldr r1, _082478EC @ =0x04000134
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	subs r1, #0xc
	ldr r2, _082478F0 @ =0x00005003
	adds r0, r2, #0
	strh r0, [r1]
	bl FUN_08247a60
	bl FUN_08247a6c
	ldr r3, _082478F4 @ =0x04000208
	ldrh r2, [r3]
	strh r4, [r3]
	ldr r4, _082478F8 @ =0x04000200
	ldrh r0, [r4]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r4]
	strh r2, [r3]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082478E4: .4byte 0x08248360
_082478E8: .4byte 0x030057D0
_082478EC: .4byte 0x04000134
_082478F0: .4byte 0x00005003
_082478F4: .4byte 0x04000208
_082478F8: .4byte 0x04000200

	thumb_func_start FUN_082478fc
FUN_082478fc: @ 0x082478FC
	push {r4, r5, lr}
	ldr r2, _08247928 @ =FUN_08248020
	str r2, [r0]
	ldr r5, _0824792C @ =0x030057D0
	ldr r0, [r5]
	movs r4, #0
	strb r1, [r0, #0xa]
	ldr r3, _08247930 @ =0x04000208
	ldrh r2, [r3]
	strh r4, [r3]
	ldr r4, _08247934 @ =0x04000200
	ldr r1, [r5]
	movs r0, #8
	ldrb r1, [r1, #0xa]
	lsls r0, r1
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	strh r2, [r3]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08247928: .4byte FUN_08248020
_0824792C: .4byte 0x030057D0
_08247930: .4byte 0x04000208
_08247934: .4byte 0x04000200

	thumb_func_start FUN_08247938
FUN_08247938: @ 0x08247938
	push {r4, r5, lr}
	ldr r5, _082479D0 @ =0x04000134
	movs r1, #0x80
	lsls r1, r1, #8
	adds r0, r1, #0
	strh r0, [r5]
	ldr r2, _082479D4 @ =0x000080A0
	adds r0, r2, #0
	strh r0, [r5]
	ldr r1, _082479D8 @ =0x030057D0
	ldr r0, [r1]
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #2
	ldr r3, _082479DC @ =0x04000100
	adds r2, r0, r3
	ldr r4, _082479E0 @ =0x04000102
	adds r3, r0, r4
	movs r0, #0
	strh r0, [r3]
	strh r0, [r2]
	movs r0, #0x83
	strh r0, [r3]
	ldrh r0, [r2]
	adds r4, r1, #0
	cmp r0, #0x11
	bhi _08247978
	ldr r0, _082479E4 @ =0x000080A2
	adds r1, r0, #0
_08247970:
	strh r1, [r5]
	ldrh r0, [r2]
	cmp r0, #0x11
	bls _08247970
_08247978:
	movs r0, #3
	strh r0, [r3]
	ldr r1, _082479D0 @ =0x04000134
	ldr r2, _082479D4 @ =0x000080A0
	adds r0, r2, #0
	strh r0, [r1]
	subs r1, #0xc
	ldr r3, _082479E8 @ =0x00005003
	adds r0, r3, #0
	strh r0, [r1]
	ldr r0, [r4]
	movs r2, #0
	str r2, [r0]
	strb r2, [r0, #4]
	ldr r0, [r4]
	strb r2, [r0, #5]
	ldr r0, [r4]
	strb r2, [r0, #6]
	ldr r0, [r4]
	strb r2, [r0, #7]
	ldr r0, [r4]
	strb r2, [r0, #8]
	ldr r0, [r4]
	strb r2, [r0, #9]
	ldr r0, [r4]
	str r2, [r0, #0xc]
	ldrb r1, [r0, #0x10]
	strb r2, [r0, #0x10]
	ldr r1, [r4]
	ldrh r0, [r1, #0x12]
	movs r3, #0
	strh r2, [r1, #0x12]
	ldrb r0, [r1, #0x14]
	movs r0, #1
	strb r0, [r1, #0x14]
	ldr r0, [r4]
	strb r3, [r0, #0x15]
	ldr r0, [r4]
	adds r0, #0x2c
	ldrb r1, [r0]
	strb r3, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_082479D0: .4byte 0x04000134
_082479D4: .4byte 0x000080A0
_082479D8: .4byte 0x030057D0
_082479DC: .4byte 0x04000100
_082479E0: .4byte 0x04000102
_082479E4: .4byte 0x000080A2
_082479E8: .4byte 0x00005003
_082479EC:
	.byte 0x00, 0x06, 0x00, 0x0E
	.byte 0x02, 0x49, 0x09, 0x68, 0x0A, 0x7D, 0x08, 0x75, 0x70, 0x47, 0x00, 0x00, 0xD0, 0x57, 0x00, 0x03

	thumb_func_start FUN_08247a00
FUN_08247a00: @ 0x08247A00
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r1, r0, #0
	cmp r0, #1
	beq _08247A2C
	cmp r0, #1
	bgt _08247A16
	cmp r0, #0
	beq _08247A20
	b _08247A54
_08247A16:
	cmp r1, #2
	beq _08247A38
	cmp r1, #3
	beq _08247A48
	b _08247A54
_08247A20:
	ldr r0, _08247A28 @ =0x030057D0
	ldr r0, [r0]
	ldrh r0, [r0, #0x12]
	b _08247A56
	.align 2, 0
_08247A28: .4byte 0x030057D0
_08247A2C:
	ldr r0, _08247A34 @ =0x030057D0
	ldr r0, [r0]
	ldrb r0, [r0, #0x14]
	b _08247A56
	.align 2, 0
_08247A34: .4byte 0x030057D0
_08247A38:
	ldr r0, _08247A44 @ =0x030057D0
	ldr r0, [r0]
	ldr r0, [r0]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _08247A56
	.align 2, 0
_08247A44: .4byte 0x030057D0
_08247A48:
	ldr r0, _08247A50 @ =0x030057D0
	ldr r0, [r0]
	ldrb r0, [r0, #6]
	b _08247A56
	.align 2, 0
_08247A50: .4byte 0x030057D0
_08247A54:
	ldr r0, _08247A5C @ =0x0000FFFF
_08247A56:
	pop {r1}
	bx r1
	.align 2, 0
_08247A5C: .4byte 0x0000FFFF

	thumb_func_start FUN_08247a60
FUN_08247a60: @ 0x08247A60
	push {lr}
	movs r0, #0
	bl FUN_08247a78
	pop {r0}
	bx r0

	thumb_func_start FUN_08247a6c
FUN_08247a6c: @ 0x08247A6C
	push {lr}
	movs r0, #0
	bl FUN_08247a84
	pop {r0}
	bx r0

	thumb_func_start FUN_08247a78
FUN_08247a78: @ 0x08247A78
	ldr r1, _08247A80 @ =0x030057D0
	ldr r1, [r1]
	str r0, [r1, #0x18]
	bx lr
	.align 2, 0
_08247A80: .4byte 0x030057D0

	thumb_func_start FUN_08247a84
FUN_08247a84: @ 0x08247A84
	ldr r1, _08247A8C @ =0x030057D0
	ldr r1, [r1]
	str r0, [r1, #0x1c]
	bx lr
	.align 2, 0
_08247A8C: .4byte 0x030057D0

	thumb_func_start FUN_08247a90
FUN_08247a90: @ 0x08247A90
	ldr r1, _08247A98 @ =0x030057D0
	ldr r1, [r1]
	str r0, [r1, #0x20]
	bx lr
	.align 2, 0
_08247A98: .4byte 0x030057D0

	thumb_func_start FUN_08247a9c
FUN_08247a9c: @ 0x08247A9C
	push {lr}
	ldr r0, _08247AC0 @ =0x030057D0
	ldr r1, [r0]
	adds r2, r1, #0
	adds r2, #0x2c
	ldrb r1, [r2]
	adds r3, r0, #0
	cmp r1, #1
	bne _08247AB6
	adds r1, r2, #0
_08247AB0:
	ldrb r0, [r1]
	cmp r0, #1
	beq _08247AB0
_08247AB6:
	ldr r0, [r3]
	ldrh r0, [r0, #0x12]
	pop {r1}
	bx r1
	.align 2, 0
_08247AC0: .4byte 0x030057D0

	thumb_func_start FUN_08247ac4
FUN_08247ac4: @ 0x08247AC4
	push {lr}
	movs r0, #0x10
	bl FUN_0824815c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08247ADE
	ldr r0, _08247AE4 @ =0x030057D0
	ldr r0, [r0]
	strb r1, [r0, #4]
	bl FUN_08248234
_08247ADE:
	pop {r0}
	bx r0
	.align 2, 0
_08247AE4: .4byte 0x030057D0

	thumb_func_start FUN_08247ae8
FUN_08247ae8: @ 0x08247AE8
	push {lr}
	movs r0, #0x11
	bl FUN_0824815c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08247B02
	ldr r0, _08247B08 @ =0x030057D0
	ldr r0, [r0]
	strb r1, [r0, #4]
	bl FUN_08248234
_08247B02:
	pop {r0}
	bx r0
	.align 2, 0
_08247B08: .4byte 0x030057D0
_08247B0C:
	.byte 0x00, 0xB5, 0x12, 0x20
	.byte 0x00, 0xF0, 0x24, 0xFB, 0x00, 0x04, 0x01, 0x0C, 0x00, 0x29, 0x04, 0xD1, 0x03, 0x48, 0x00, 0x68
	.byte 0x01, 0x71, 0x00, 0xF0, 0x87, 0xFB, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0xD0, 0x57, 0x00, 0x03

	thumb_func_start FUN_08247b30
FUN_08247b30: @ 0x08247B30
	push {lr}
	movs r0, #0x13
	bl FUN_0824815c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08247B4A
	ldr r0, _08247B50 @ =0x030057D0
	ldr r0, [r0]
	strb r1, [r0, #4]
	bl FUN_08248234
_08247B4A:
	pop {r0}
	bx r0
	.align 2, 0
_08247B50: .4byte 0x030057D0

	thumb_func_start FUN_08247b54
FUN_08247b54: @ 0x08247B54
	push {lr}
	movs r0, #0x14
	bl FUN_0824815c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08247B6E
	ldr r0, _08247B74 @ =0x030057D0
	ldr r0, [r0]
	strb r1, [r0, #4]
	bl FUN_08248234
_08247B6E:
	pop {r0}
	bx r0
	.align 2, 0
_08247B74: .4byte 0x030057D0
_08247B78:
	.byte 0x00, 0xB5, 0x15, 0x20, 0x00, 0xF0, 0xEE, 0xFA
	.byte 0x00, 0x04, 0x01, 0x0C, 0x00, 0x29, 0x04, 0xD1, 0x03, 0x48, 0x00, 0x68, 0x01, 0x71, 0x00, 0xF0
	.byte 0x51, 0xFB, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0xD0, 0x57, 0x00, 0x03

	thumb_func_start FUN_08247b9c
FUN_08247b9c: @ 0x08247B9C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #0x16
	bl FUN_0824815c
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08247BE8
	ldr r2, _08247BF0 @ =0x030057D0
	ldr r1, [r2]
	movs r0, #6
	strb r0, [r1, #4]
	ldr r0, [r2]
	ldr r1, [r0, #0x24]
	adds r1, #4
	ldrh r0, [r4]
	strh r0, [r1]
	adds r1, #2
	adds r4, #2
	movs r2, #0xd
_08247BC6:
	ldrb r0, [r4]
	strb r0, [r1]
	adds r1, #1
	adds r4, #1
	subs r2, #1
	cmp r2, #0
	bge _08247BC6
	movs r2, #7
_08247BD6:
	ldrb r0, [r5]
	strb r0, [r1]
	adds r1, #1
	adds r5, #1
	subs r2, #1
	cmp r2, #0
	bge _08247BD6
	bl FUN_08248234
_08247BE8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08247BF0: .4byte 0x030057D0

	thumb_func_start FUN_08247bf4
FUN_08247bf4: @ 0x08247BF4
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r4, r2, #0x18
	movs r0, #0x17
	bl FUN_0824815c
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08247C2A
	ldr r2, _08247C30 @ =0x030057D0
	ldr r1, [r2]
	movs r0, #1
	strb r0, [r1, #4]
	ldr r0, [r2]
	ldr r0, [r0, #0x24]
	adds r0, #4
	strb r4, [r0]
	adds r0, #1
	strb r5, [r0]
	adds r0, #1
	strh r6, [r0]
	bl FUN_08248234
_08247C2A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08247C30: .4byte 0x030057D0

	thumb_func_start FUN_08247c34
FUN_08247c34: @ 0x08247C34
	push {lr}
	movs r0, #0x19
	bl FUN_0824815c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08247C4E
	ldr r0, _08247C54 @ =0x030057D0
	ldr r0, [r0]
	strb r1, [r0, #4]
	bl FUN_08248234
_08247C4E:
	pop {r0}
	bx r0
	.align 2, 0
_08247C54: .4byte 0x030057D0

	thumb_func_start FUN_08247c58
FUN_08247c58: @ 0x08247C58
	push {lr}
	movs r0, #0x1a
	bl FUN_0824815c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08247C72
	ldr r0, _08247C78 @ =0x030057D0
	ldr r0, [r0]
	strb r1, [r0, #4]
	bl FUN_08248234
_08247C72:
	pop {r0}
	bx r0
	.align 2, 0
_08247C78: .4byte 0x030057D0

	thumb_func_start FUN_08247c7c
FUN_08247c7c: @ 0x08247C7C
	push {lr}
	movs r0, #0x1b
	bl FUN_0824815c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08247C96
	ldr r0, _08247C9C @ =0x030057D0
	ldr r0, [r0]
	strb r1, [r0, #4]
	bl FUN_08248234
_08247C96:
	pop {r0}
	bx r0
	.align 2, 0
_08247C9C: .4byte 0x030057D0

	thumb_func_start FUN_08247ca0
FUN_08247ca0: @ 0x08247CA0
	push {lr}
	movs r0, #0x1c
	bl FUN_0824815c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08247CBA
	ldr r0, _08247CC0 @ =0x030057D0
	ldr r0, [r0]
	strb r1, [r0, #4]
	bl FUN_08248234
_08247CBA:
	pop {r0}
	bx r0
	.align 2, 0
_08247CC0: .4byte 0x030057D0

	thumb_func_start FUN_08247cc4
FUN_08247cc4: @ 0x08247CC4
	push {lr}
	movs r0, #0x1d
	bl FUN_0824815c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08247CDE
	ldr r0, _08247CE4 @ =0x030057D0
	ldr r0, [r0]
	strb r1, [r0, #4]
	bl FUN_08248234
_08247CDE:
	pop {r0}
	bx r0
	.align 2, 0
_08247CE4: .4byte 0x030057D0

	thumb_func_start FUN_08247ce8
FUN_08247ce8: @ 0x08247CE8
	push {lr}
	movs r0, #0x1e
	bl FUN_0824815c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08247D02
	ldr r0, _08247D08 @ =0x030057D0
	ldr r0, [r0]
	strb r1, [r0, #4]
	bl FUN_08248234
_08247D02:
	pop {r0}
	bx r0
	.align 2, 0
_08247D08: .4byte 0x030057D0

	thumb_func_start FUN_08247d0c
FUN_08247d0c: @ 0x08247D0C
	push {r4, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0x1f
	bl FUN_0824815c
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08247D30
	ldr r2, _08247D38 @ =0x030057D0
	ldr r1, [r2]
	movs r0, #1
	strb r0, [r1, #4]
	ldr r0, [r2]
	ldr r0, [r0, #0x24]
	str r4, [r0, #4]
	bl FUN_08248234
_08247D30:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08247D38: .4byte 0x030057D0

	thumb_func_start FUN_08247d3c
FUN_08247d3c: @ 0x08247D3C
	push {lr}
	movs r0, #0x20
	bl FUN_0824815c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08247D56
	ldr r0, _08247D5C @ =0x030057D0
	ldr r0, [r0]
	strb r1, [r0, #4]
	bl FUN_08248234
_08247D56:
	pop {r0}
	bx r0
	.align 2, 0
_08247D5C: .4byte 0x030057D0

	thumb_func_start FUN_08247d60
FUN_08247d60: @ 0x08247D60
	push {lr}
	movs r0, #0x21
	bl FUN_0824815c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08247D7A
	ldr r0, _08247D80 @ =0x030057D0
	ldr r0, [r0]
	strb r1, [r0, #4]
	bl FUN_08248234
_08247D7A:
	pop {r0}
	bx r0
	.align 2, 0
_08247D80: .4byte 0x030057D0

	thumb_func_start FUN_08247d84
FUN_08247d84: @ 0x08247D84
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r4, r1, #0x18
	lsrs r5, r4, #0x18
	movs r0, #0x24
	bl FUN_0824815c
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08247DC2
	lsrs r2, r4, #0x1a
	movs r0, #3
	ands r0, r5
	cmp r0, #0
	beq _08247DA4
	adds r2, #1
_08247DA4:
	ldr r1, _08247DC8 @ =0x030057D0
	ldr r0, [r1]
	strb r2, [r0, #4]
	ldr r0, [r1]
	ldr r1, [r0, #0x24]
	adds r1, #4
	ldrb r2, [r0, #4]
	movs r0, #0x80
	lsls r0, r0, #0x13
	orrs r2, r0
	adds r0, r6, #0
	bl CpuSet
	bl FUN_08248234
_08247DC2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08247DC8: .4byte 0x030057D0

	thumb_func_start FUN_08247dcc
FUN_08247dcc: @ 0x08247DCC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	lsls r4, r1, #0x18
	lsrs r5, r4, #0x18
	movs r0, #0x25
	bl FUN_0824815c
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08247E0A
	lsrs r2, r4, #0x1a
	movs r0, #3
	ands r0, r5
	cmp r0, #0
	beq _08247DEC
	adds r2, #1
_08247DEC:
	ldr r1, _08247E10 @ =0x030057D0
	ldr r0, [r1]
	strb r2, [r0, #4]
	ldr r0, [r1]
	ldr r1, [r0, #0x24]
	adds r1, #4
	ldrb r2, [r0, #4]
	movs r0, #0x80
	lsls r0, r0, #0x13
	orrs r2, r0
	adds r0, r6, #0
	bl CpuSet
	bl FUN_08248234
_08247E0A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08247E10: .4byte 0x030057D0

	thumb_func_start FUN_08247e14
FUN_08247e14: @ 0x08247E14
	push {lr}
	movs r0, #0x26
	bl FUN_0824815c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08247E2E
	ldr r0, _08247E34 @ =0x030057D0
	ldr r0, [r0]
	strb r1, [r0, #4]
	bl FUN_08248234
_08247E2E:
	pop {r0}
	bx r0
	.align 2, 0
_08247E34: .4byte 0x030057D0

	thumb_func_start FUN_08247e38
FUN_08247e38: @ 0x08247E38
	push {lr}
	movs r0, #0x27
	bl FUN_0824815c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08247E52
	ldr r0, _08247E58 @ =0x030057D0
	ldr r0, [r0]
	strb r1, [r0, #4]
	bl FUN_08248234
_08247E52:
	pop {r0}
	bx r0
	.align 2, 0
_08247E58: .4byte 0x030057D0
_08247E5C:
	.byte 0x30, 0xB5, 0x00, 0x06
	.byte 0x04, 0x0E, 0x25, 0x1C, 0x28, 0x20, 0x00, 0xF0, 0x79, 0xF9, 0x00, 0x04, 0x03, 0x0C, 0x00, 0x2B
	.byte 0x17, 0xD1, 0x00, 0x2C, 0x06, 0xD1, 0x02, 0x48, 0x00, 0x68, 0x03, 0x71, 0x0F, 0xE0, 0x00, 0x00
	.byte 0xD0, 0x57, 0x00, 0x03, 0x08, 0x4A, 0x11, 0x68, 0x01, 0x20, 0x08, 0x71, 0x10, 0x68, 0x40, 0x6A
	.byte 0x04, 0x30, 0x05, 0x70, 0x01, 0x30, 0x03, 0x70, 0x01, 0x30, 0x03, 0x70, 0x43, 0x70, 0x00, 0xF0
	.byte 0xC9, 0xF9, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0xD0, 0x57, 0x00, 0x03, 0x30, 0xB5, 0x00, 0x06
	.byte 0x04, 0x0E, 0x09, 0x06, 0x0D, 0x0E, 0x29, 0x20, 0x00, 0xF0, 0x50, 0xF9, 0x00, 0x04, 0x03, 0x0C
	.byte 0x00, 0x2B, 0x0E, 0xD1, 0x08, 0x4A, 0x11, 0x68, 0x01, 0x20, 0x08, 0x71, 0x10, 0x68, 0x40, 0x6A
	.byte 0x04, 0x30, 0x04, 0x70, 0x01, 0x30, 0x05, 0x70, 0x01, 0x30, 0x03, 0x70, 0x43, 0x70, 0x00, 0xF0
	.byte 0xA9, 0xF9, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0xD0, 0x57, 0x00, 0x03

	thumb_func_start FUN_08247eec
FUN_08247eec: @ 0x08247EEC
	push {lr}
	movs r0, #0x37
	bl FUN_0824815c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08247F06
	ldr r0, _08247F0C @ =0x030057D0
	ldr r0, [r0]
	strb r1, [r0, #4]
	bl FUN_08248234
_08247F06:
	pop {r0}
	bx r0
	.align 2, 0
_08247F0C: .4byte 0x030057D0

	thumb_func_start FUN_08247f10
FUN_08247f10: @ 0x08247F10
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r0, #0x30
	bl FUN_0824815c
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08247F34
	ldr r2, _08247F3C @ =0x030057D0
	ldr r1, [r2]
	movs r0, #1
	strb r0, [r1, #4]
	ldr r0, [r2]
	ldr r0, [r0, #0x24]
	str r4, [r0, #4]
	bl FUN_08248234
_08247F34:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08247F3C: .4byte 0x030057D0

	thumb_func_start FUN_08247f40
FUN_08247f40: @ 0x08247F40
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r4, r1, #0x18
	movs r0, #0x31
	bl FUN_0824815c
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08247F6C
	ldr r2, _08247F74 @ =0x030057D0
	ldr r1, [r2]
	movs r0, #1
	strb r0, [r1, #4]
	ldr r0, [r2]
	ldr r1, [r0, #0x24]
	lsls r0, r4, #8
	orrs r0, r5
	str r0, [r1, #4]
	bl FUN_08248234
_08247F6C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08247F74: .4byte 0x030057D0

	thumb_func_start FUN_08247f78
FUN_08247f78: @ 0x08247F78
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	movs r0, #0x32
	bl FUN_0824815c
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08247FAA
	ldr r2, _08247FB0 @ =0x030057D0
	ldr r1, [r2]
	movs r0, #2
	strb r0, [r1, #4]
	lsls r0, r5, #0x10
	orrs r0, r4
	ldr r1, [r2]
	ldr r1, [r1, #0x24]
	str r0, [r1, #4]
	str r6, [r1, #8]
	bl FUN_08248234
_08247FAA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08247FB0: .4byte 0x030057D0

	thumb_func_start FUN_08247fb4
FUN_08247fb4: @ 0x08247FB4
	push {lr}
	movs r0, #0x33
	bl FUN_0824815c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08247FCE
	ldr r0, _08247FD4 @ =0x030057D0
	ldr r0, [r0]
	strb r1, [r0, #4]
	bl FUN_08248234
_08247FCE:
	pop {r0}
	bx r0
	.align 2, 0
_08247FD4: .4byte 0x030057D0

	thumb_func_start FUN_08247fd8
FUN_08247fd8: @ 0x08247FD8
	push {lr}
	movs r0, #0x34
	bl FUN_0824815c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08247FF2
	ldr r0, _08247FF8 @ =0x030057D0
	ldr r0, [r0]
	strb r1, [r0, #4]
	bl FUN_08248234
_08247FF2:
	pop {r0}
	bx r0
	.align 2, 0
_08247FF8: .4byte 0x030057D0

	thumb_func_start FUN_08247ffc
FUN_08247ffc: @ 0x08247FFC
	push {lr}
	movs r0, #0x3d
	bl FUN_0824815c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08248016
	ldr r0, _0824801C @ =0x030057D0
	ldr r0, [r0]
	strb r1, [r0, #4]
	bl FUN_08248234
_08248016:
	pop {r0}
	bx r0
	.align 2, 0
_0824801C: .4byte 0x030057D0

	thumb_func_start FUN_08248020
FUN_08248020: @ 0x08248020
	push {r4, lr}
	ldr r4, _08248038 @ =0x030057D0
	ldr r1, [r4]
	ldr r0, [r1, #0xc]
	cmp r0, #2
	beq _08248046
	cmp r0, #2
	bhi _0824803C
	cmp r0, #1
	beq _08248054
	b _0824807C
	.align 2, 0
_08248038: .4byte 0x030057D0
_0824803C:
	cmp r0, #3
	beq _0824805E
	cmp r0, #4
	beq _08248054
	b _0824807C
_08248046:
	ldrb r0, [r1, #0x10]
	movs r0, #1
	strb r0, [r1, #0x10]
	movs r0, #0x32
	bl FUN_08248084
	b _0824807C
_08248054:
	bl FUN_08248130
	bl FUN_082482a8
	b _0824807C
_0824805E:
	ldrb r0, [r1, #0x10]
	movs r0, #1
	strb r0, [r1, #0x10]
	bl FUN_08248130
	bl FUN_08248328
	ldr r0, [r4]
	ldr r2, [r0, #0x18]
	cmp r2, #0
	beq _0824807C
	movs r0, #0xff
	movs r1, #0
	bl _call_via_r2
_0824807C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08248084
FUN_08248084: @ 0x08248084
	push {r4, r5, r6, r7, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r5, r3, #0
	ldr r2, _082480B4 @ =0x030057D0
	ldr r0, [r2]
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #2
	ldr r1, _082480B8 @ =0x04000100
	adds r4, r0, r1
	adds r1, #2
	adds r7, r0, r1
	ldr r1, _082480BC @ =0x04000208
	movs r0, #0
	strh r0, [r1]
	adds r6, r2, #0
	cmp r3, #0x50
	beq _082480DC
	cmp r3, #0x50
	bgt _082480C0
	cmp r3, #0x32
	beq _082480CA
	b _08248108
	.align 2, 0
_082480B4: .4byte 0x030057D0
_082480B8: .4byte 0x04000100
_082480BC: .4byte 0x04000208
_082480C0:
	cmp r5, #0x64
	beq _082480EC
	cmp r5, #0x82
	beq _082480FC
	b _08248108
_082480CA:
	ldr r1, _082480D8 @ =0x0000FCCB
	adds r0, r1, #0
	strh r0, [r4]
	ldr r1, [r6]
	movs r0, #1
	b _08248106
	.align 2, 0
_082480D8: .4byte 0x0000FCCB
_082480DC:
	ldr r1, _082480E8 @ =0x0000FAE0
	adds r0, r1, #0
	strh r0, [r4]
	ldr r1, [r6]
	movs r0, #2
	b _08248106
	.align 2, 0
_082480E8: .4byte 0x0000FAE0
_082480EC:
	ldr r1, _082480F8 @ =0x0000F996
	adds r0, r1, #0
	strh r0, [r4]
	ldr r1, [r6]
	movs r0, #3
	b _08248106
	.align 2, 0
_082480F8: .4byte 0x0000F996
_082480FC:
	ldr r1, _08248124 @ =0x0000F7AD
	adds r0, r1, #0
	strh r0, [r4]
	ldr r1, [r6]
	movs r0, #4
_08248106:
	str r0, [r1, #0xc]
_08248108:
	movs r0, #0xc3
	strh r0, [r7]
	ldr r2, _08248128 @ =0x04000202
	ldr r1, [r6]
	movs r0, #8
	ldrb r1, [r1, #0xa]
	lsls r0, r1
	strh r0, [r2]
	ldr r1, _0824812C @ =0x04000208
	movs r0, #1
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08248124: .4byte 0x0000F7AD
_08248128: .4byte 0x04000202
_0824812C: .4byte 0x04000208

	thumb_func_start FUN_08248130
FUN_08248130: @ 0x08248130
	ldr r2, _08248150 @ =0x030057D0
	ldr r0, [r2]
	movs r1, #0
	str r1, [r0, #0xc]
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #2
	ldr r3, _08248154 @ =0x04000100
	adds r0, r0, r3
	strh r1, [r0]
	ldr r0, [r2]
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #2
	ldr r2, _08248158 @ =0x04000102
	adds r0, r0, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_08248150: .4byte 0x030057D0
_08248154: .4byte 0x04000100
_08248158: .4byte 0x04000102

	thumb_func_start FUN_0824815c
FUN_0824815c: @ 0x0824815C
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r6, r5, #0
	ldr r0, _08248188 @ =0x04000208
	ldrh r0, [r0]
	cmp r0, #0
	bne _08248190
	ldr r0, _0824818C @ =0x030057D0
	ldr r1, [r0]
	ldrh r0, [r1, #0x12]
	movs r0, #6
	strh r0, [r1, #0x12]
	ldr r2, [r1, #0x18]
	cmp r2, #0
	beq _082481DA
	ldrh r1, [r1, #0x12]
	adds r0, r5, #0
	bl _call_via_r2
	b _082481DA
	.align 2, 0
_08248188: .4byte 0x04000208
_0824818C: .4byte 0x030057D0
_08248190:
	ldr r4, _082481BC @ =0x030057D0
	ldr r2, [r4]
	adds r3, r2, #0
	adds r3, #0x2c
	ldrb r0, [r3]
	cmp r0, #1
	bne _082481C0
	ldrh r0, [r2, #0x12]
	movs r1, #0
	movs r0, #2
	strh r0, [r2, #0x12]
	ldrb r0, [r3]
	strb r1, [r3]
	ldr r0, [r4]
	ldr r2, [r0, #0x18]
	cmp r2, #0
	beq _082481DA
	ldrh r1, [r0, #0x12]
	adds r0, r5, #0
	bl _call_via_r2
	b _082481DA
	.align 2, 0
_082481BC: .4byte 0x030057D0
_082481C0:
	ldrb r0, [r2, #0x14]
	cmp r0, #0
	bne _082481DE
	ldrh r0, [r2, #0x12]
	movs r0, #4
	strh r0, [r2, #0x12]
	ldr r3, [r2, #0x18]
	cmp r3, #0
	beq _082481DA
	ldrh r1, [r2, #0x12]
	adds r0, r5, #0
	bl _call_via_r3
_082481DA:
	movs r0, #1
	b _08248226
_082481DE:
	ldrb r0, [r3]
	movs r1, #0
	movs r0, #1
	strb r0, [r3]
	ldr r0, [r4]
	strb r6, [r0, #6]
	ldr r0, [r4]
	str r1, [r0]
	strb r1, [r0, #4]
	ldr r0, [r4]
	strb r1, [r0, #5]
	ldr r0, [r4]
	strb r1, [r0, #7]
	ldr r0, [r4]
	strb r1, [r0, #8]
	ldr r0, [r4]
	strb r1, [r0, #9]
	ldr r0, [r4]
	str r1, [r0, #0xc]
	ldrb r2, [r0, #0x10]
	strb r1, [r0, #0x10]
	ldr r0, [r4]
	ldrh r2, [r0, #0x12]
	movs r2, #0
	strh r1, [r0, #0x12]
	strb r2, [r0, #0x15]
	ldr r1, _0824822C @ =0x04000134
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	subs r1, #0xc
	ldr r2, _08248230 @ =0x00005003
	adds r0, r2, #0
	strh r0, [r1]
	movs r0, #0
_08248226:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0824822C: .4byte 0x04000134
_08248230: .4byte 0x00005003

	thumb_func_start FUN_08248234
FUN_08248234: @ 0x08248234
	push {r4, r5, lr}
	ldr r5, _0824828C @ =0x030057D0
	ldr r0, [r5]
	ldr r3, [r0, #0x24]
	ldrb r1, [r0, #4]
	lsls r1, r1, #8
	ldrb r0, [r0, #6]
	ldr r2, _08248290 @ =0x99660000
	orrs r0, r2
	orrs r1, r0
	str r1, [r3]
	ldr r2, _08248294 @ =0x04000120
	ldr r1, [r5]
	ldr r0, [r1, #0x24]
	ldr r0, [r0]
	str r0, [r2]
	movs r2, #0
	str r2, [r1]
	movs r0, #1
	strb r0, [r1, #5]
	ldr r4, _08248298 @ =0x04000208
	ldrh r3, [r4]
	strh r2, [r4]
	ldr r2, _0824829C @ =0x04000200
	ldr r1, [r5]
	movs r0, #8
	ldrb r1, [r1, #0xa]
	lsls r0, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	strh r3, [r4]
	ldr r1, _082482A0 @ =0x04000128
	ldr r2, _082482A4 @ =0x00005083
	adds r0, r2, #0
	strh r0, [r1]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0824828C: .4byte 0x030057D0
_08248290: .4byte 0x99660000
_08248294: .4byte 0x04000120
_08248298: .4byte 0x04000208
_0824829C: .4byte 0x04000200
_082482A0: .4byte 0x04000128
_082482A4: .4byte 0x00005083

	thumb_func_start FUN_082482a8
FUN_082482a8: @ 0x082482A8
	push {r4, lr}
	ldr r4, _082482C0 @ =0x030057D0
	ldr r2, [r4]
	ldrb r0, [r2, #0x15]
	adds r3, r4, #0
	cmp r0, #1
	bhi _082482C4
	adds r0, #1
	strb r0, [r2, #0x15]
	bl FUN_08248234
	b _0824831E
	.align 2, 0
_082482C0: .4byte 0x030057D0
_082482C4:
	ldrb r0, [r2, #6]
	cmp r0, #0x27
	beq _082482D6
	cmp r0, #0x25
	beq _082482D6
	cmp r0, #0x35
	beq _082482D6
	cmp r0, #0x37
	bne _082482F8
_082482D6:
	ldr r0, [r3]
	ldrh r1, [r0, #0x12]
	movs r2, #0
	movs r1, #1
	strh r1, [r0, #0x12]
	adds r0, #0x2c
	ldrb r1, [r0]
	strb r2, [r0]
	ldr r1, [r3]
	ldr r2, [r1, #0x18]
	cmp r2, #0
	beq _0824831E
	ldrb r0, [r1, #6]
	ldrh r1, [r1, #0x12]
	bl _call_via_r2
	b _0824831E
_082482F8:
	ldrh r0, [r2, #0x12]
	movs r1, #0
	movs r0, #1
	strh r0, [r2, #0x12]
	adds r0, r2, #0
	adds r0, #0x2c
	ldrb r2, [r0]
	strb r1, [r0]
	ldr r1, [r4]
	ldr r2, [r1, #0x18]
	cmp r2, #0
	beq _08248318
	ldrb r0, [r1, #6]
	ldrh r1, [r1, #0x12]
	bl _call_via_r2
_08248318:
	ldr r1, [r4]
	movs r0, #4
	str r0, [r1]
_0824831E:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08248328
FUN_08248328: @ 0x08248328
	ldr r3, _08248354 @ =0x030057D0
	ldr r1, [r3]
	movs r0, #5
	str r0, [r1]
	movs r2, #0
	strb r2, [r1, #4]
	ldr r0, [r3]
	strb r2, [r0, #5]
	ldr r1, _08248358 @ =0x04000120
	movs r0, #0x80
	lsls r0, r0, #0x18
	str r0, [r1]
	adds r1, #8
	strh r2, [r1]
	ldr r2, _0824835C @ =0x00005003
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #0x7f
	adds r0, r2, #0
	strh r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_08248354: .4byte 0x030057D0
_08248358: .4byte 0x04000120
_0824835C: .4byte 0x00005003
_08248360:
	.byte 0x0D, 0xC0, 0xA0, 0xE1, 0x00, 0xD8, 0x2D, 0xE9, 0x50, 0x30, 0x9F, 0xE5, 0x00, 0x00, 0x93, 0xE5
	.byte 0x00, 0x20, 0x90, 0xE5, 0x04, 0xB0, 0x4C, 0xE2, 0x0A, 0x00, 0x52, 0xE3, 0x06, 0x00, 0x00, 0x1A
	.byte 0x20, 0x00, 0x90, 0xE5, 0x00, 0x00, 0x50, 0xE3, 0x00, 0x68, 0x1B, 0x09, 0x1E, 0xFF, 0x2F, 0x01
	.byte 0x49, 0x02, 0x00, 0xEB, 0x00, 0x68, 0x1B, 0xE9, 0x1E, 0xFF, 0x2F, 0xE1, 0x14, 0x30, 0xD0, 0xE5
	.byte 0x01, 0x00, 0x53, 0xE3, 0x02, 0x00, 0x00, 0x1A, 0x05, 0x00, 0x00, 0xEB, 0x00, 0x68, 0x1B, 0xE9
	.byte 0x1E, 0xFF, 0x2F, 0xE1, 0xA6, 0x00, 0x00, 0xEB, 0x00, 0x68, 0x1B, 0xE9, 0x1E, 0xFF, 0x2F, 0xE1
	.byte 0xD0, 0x57, 0x00, 0x03

	arm_func_start FUN_082483c4
FUN_082483c4: @ 0x082483C4
	mov ip, sp
	push {r4, r5, r6, fp, ip, lr, pc}
	mov r0, #0x50
	sub fp, ip, #4
	bl FUN_08248ac8
	mov r4, #0x120
	ldr r2, _08248638 @ =0x030057D0
	add r4, r4, #0x4000000
	ldr lr, [r4]
	ldr ip, [r2]
	ldr r3, [ip]
	mov r6, r2
	cmp r3, #0
	bne _08248444
	cmp lr, #-0x80000000
	bne _082484C4
	ldrb r2, [ip, #5]
	ldrb r3, [ip, #4]
	cmp r2, r3
	bhi _08248434
	ldr r3, [ip, #0x24]
	mov r1, r2
	ldr r2, [r3, r1, lsl #2]
	str r2, [r4]
	ldrb r3, [ip, #5]
	add r3, r3, #1
	strb r3, [ip, #5]
	b _08248520
_08248434:
	mov r3, #1
	str r3, [ip]
	str lr, [r4]
	b _08248520
_08248444:
	ldr r3, [ip]
	cmp r3, #1
	bne _082484D4
	mov r3, #-0x67000000
	add r3, r3, #0x660000
	mov r5, #-0x80000000
	and r2, lr, r5, asr #15
	cmp r2, r3
	bne _082484C4
	mov r3, #0
	strb r3, [ip, #8]
	ldr r1, [r6]
	ldrb r0, [r1, #8]
	ldr r2, [r1, #0x28]
	str lr, [r2, r0, lsl #2]
	ldrb r3, [r1, #8]
	add r3, r3, #1
	strb r3, [r1, #8]
	ldr r2, [r6]
	strb lr, [r2, #9]
	ldr r3, [r6]
	lsr r2, lr, #8
	strb r2, [r3, #7]
	ldr r1, [r6]
	ldrb r2, [r1, #7]
	ldrb r3, [r1, #8]
	cmp r2, r3
	blo _0824850C
	mov r3, #2
	str r3, [r1]
	str r5, [r4]
	b _08248520
_082484C4:
	bl FUN_08248bd8
	mov r0, #0x82
	bl FUN_08248ac8
	b _0824864C
_082484D4:
	ldr r3, [ip]
	cmp r3, #2
	bne _08248520
	ldrb r1, [ip, #8]
	ldr r2, [ip, #0x28]
	str lr, [r2, r1, lsl #2]
	ldrb r3, [ip, #8]
	add r3, r3, #1
	strb r3, [ip, #8]
	ldr r1, [r6]
	ldrb r2, [r1, #7]
	ldrb r3, [r1, #8]
	cmp r2, r3
	bhs _08248518
_0824850C:
	mov r3, #3
	str r3, [r1]
	b _08248520
_08248518:
	mov r3, #-0x80000000
	str r3, [r4]
_08248520:
	mov r0, #1
	bl FUN_08248a60
	lsl r0, r0, #0x10
	cmp r0, #0x10000
	beq _0824864C
	mov r4, #0x128
	add r4, r4, #0x4000000
	mov r5, #0x5000
	add r3, r5, #0xb
	strh r3, [r4]
	mov r0, #0
	bl FUN_08248a60
	lsl r0, r0, #0x10
	cmp r0, #0x10000
	beq _0824864C
	bl FUN_08248bd8
	ldr r1, [r6]
	ldr r0, [r1]
	cmp r0, #3
	bne _0824863C
	ldrb r3, [r1, #9]
	cmp r3, #0xa5
	cmpne r3, #0xa7
	beq _08248594
	and r3, r3, #0xff
	cmp r3, #0xb5
	beq _08248594
	cmp r3, #0xb7
	bne _082485DC
_08248594:
	mov r1, #0x120
	add r1, r1, #0x4000000
	mov ip, #0x128
	add ip, ip, #0x4000000
	ldr r0, [r6]
	mov r3, #0
	strb r3, [r0, #0x14]
	mov r2, #-0x80000000
	str r2, [r1]
	add r3, r3, #0x5000
	add r2, r3, #2
	strh r2, [ip]
	add r3, r3, #0x82
	strh r3, [ip]
	ldr r2, [r6]
	mov r3, #5
	str r3, [r2]
	b _0824860C
_082485DC:
	cmp r3, #0xee
	bne _082485FC
	add r3, r5, #3
	strh r3, [r4]
	mov r2, #4
	str r2, [r1]
	strh r0, [r1, #0x12]
	b _0824860C
_082485FC:
	add r3, r5, #3
	strh r3, [r4]
	mov r2, #4
	str r2, [r1]
_0824860C:
	ldr r2, [r6]
	mov r3, #0
	strb r3, [r2, #0x2c]
	ldr r0, [r6]
	ldr r2, [r0, #0x18]
	cmp r2, r3
	beq _0824864C
	ldrh r1, [r0, #0x12]
	ldrb r0, [r0, #6]
	bl FUN_08248cb4
	b _0824864C
	.align 2, 0
_08248638: .4byte 0x030057D0
_0824863C:
	add r3, r5, #3
	strh r3, [r4]
	add r2, r5, #0x83
	strh r2, [r4]
_0824864C:
	ldmdb fp, {r4, r5, r6, fp, sp, lr}
	bx lr

	arm_func_start FUN_08248654
FUN_08248654: @ 0x08248654
	mov ip, sp
	push {r4, r5, r6, fp, ip, lr, pc}
	ldr r4, _08248A00 @ =0x030057D0
	mov r0, #0x64
	ldr r3, [r4]
	mov r6, #0
	strb r6, [r3, #0x10]
	sub fp, ip, #4
	bl FUN_08248ac8
	mov r0, r6
	bl FUN_08248a60
	lsl r0, r0, #0x10
	cmp r0, #0x10000
	mov r5, r4
	beq _08248A58
	mov r3, #0x128
	add r3, r3, #0x4000000
	mov r2, #0x5000
	add r2, r2, #0xa
	strh r2, [r3]
	mov lr, #0x120
	ldr r0, [r5]
	add lr, lr, #0x4000000
	ldr ip, [lr]
	ldr r3, [r0]
	cmp r3, #5
	bne _08248784
	ldr r3, [r0, #0x28]
	mov r4, #1
	mov r0, #-0x67000000
	str ip, [r3]
	add r0, r0, #0x660000
	ldr r2, [r5]
	lsr r3, r0, #0x10
	strb r4, [r2, #5]
	cmp r3, ip, lsr #16
	bne _082488D0
	ldr r3, [r5]
	lsr r2, ip, #8
	strb r2, [r3, #4]
	ldr r2, [r5]
	strb ip, [r2, #6]
	ldr r1, [r5]
	ldrb r3, [r1, #4]
	cmp r3, r6
	bne _08248768
	ldrb r2, [r1, #6]
	sub r3, r2, #0x27
	cmp r2, #0x36
	cmpne r3, #2
	bhi _0824873C
	add r3, r2, #0x80
	strb r3, [r1, #9]
	ldr r2, [r5]
	ldrb r3, [r2, #9]
	ldr r1, [r2, #0x24]
	add r3, r3, r0
	b _082487EC
_0824873C:
	ldr r2, [r1, #0x24]
	ldr r3, _08248A04 @ =0x996601EE
	str r3, [r2]
	ldr r2, [r5]
	ldrb r3, [r2, #6]
	sub r3, r3, #0x10
	cmp r3, #0x2d
	bhi _08248824
	ldr r3, [r2, #0x24]
	str r4, [r3, #4]
	b _08248830
_08248768:
	mov r3, #-0x80000000
	str r3, [lr]
	strb r4, [r1, #5]
	ldr r2, [r5]
	add r3, r3, #-0x7ffffffa
	str r3, [r2]
	b _082488E0
_08248784:
	ldr r3, [r0]
	cmp r3, #6
	bne _08248884
	ldrb r1, [r0, #5]
	ldr r2, [r0, #0x28]
	str ip, [r2, r1, lsl #2]
	ldrb r3, [r0, #5]
	add r3, r3, #1
	strb r3, [r0, #5]
	ldr r1, [r5]
	ldrb r2, [r1, #4]
	ldrb r3, [r1, #5]
	cmp r2, r3
	bhs _08248878
	ldrb r2, [r1, #6]
	sub r3, r2, #0x28
	cmp r2, #0x36
	cmpne r3, #1
	bhi _082487FC
	add r3, r2, #0x80
	strb r3, [r1, #9]
	ldr r2, [r5]
	ldrb r3, [r2, #9]
	ldr r1, [r2, #0x24]
	orr r3, r3, #0x99000000
	orr r3, r3, #0x660000
_082487EC:
	str r3, [r1]
	ldr r2, [r5]
	strb r6, [r2, #7]
	b _08248848
_082487FC:
	ldr r2, [r1, #0x24]
	ldr r3, _08248A04 @ =0x996601EE
	str r3, [r2]
	ldr r2, [r5]
	ldrb r3, [r2, #6]
	sub r3, r3, #0x10
	cmp r3, #0x2d
	ldrls r2, [r2, #0x24]
	movls r3, #1
	bls _0824882C
_08248824:
	ldr r2, [r2, #0x24]
	mov r3, #2
_0824882C:
	str r3, [r2, #4]
_08248830:
	ldr r2, [r5]
	mov r3, #1
	strb r3, [r2, #7]
	ldr r1, [r5]
	add r3, r3, #2
	strh r3, [r1, #0x12]
_08248848:
	ldr r0, [r5]
	ldr r2, [r0, #0x24]
	mov r3, #0x120
	ldr r1, [r2]
	add r3, r3, #0x4000000
	str r1, [r3]
	mov r2, #1
	strb r2, [r0, #8]
	ldr r1, [r5]
	mov r3, #7
	str r3, [r1]
	b _082488E0
_08248878:
	mov r3, #-0x80000000
	str r3, [lr]
	b _082488E0
_08248884:
	ldr r3, [r0]
	cmp r3, #7
	bne _082488E0
	cmp ip, #-0x80000000
	bne _082488D0
	ldrb r2, [r0, #7]
	ldrb r3, [r0, #8]
	cmp r2, r3
	movlo r3, #8
	strlo r3, [r0]
	blo _082488E0
	ldrb r1, [r0, #8]
	ldr r3, [r0, #0x24]
	ldr r2, [r3, r1, lsl #2]
	str r2, [lr]
	ldrb r3, [r0, #8]
	add r3, r3, #1
	strb r3, [r0, #8]
	b _082488E0
_082488D0:
	bl FUN_08248bd8
	mov r0, #0x64
	bl FUN_08248ac8
	b _08248A58
_082488E0:
	mov r0, #1
	bl FUN_08248a60
	lsl r0, r0, #0x10
	cmp r0, #0x10000
	beq _08248A58
	mov r6, r5
	ldr r3, [r6]
	ldr r2, [r3]
	cmp r2, #8
	bne _082489A8
	mov r4, #0x128
	add r4, r4, #0x4000000
	mov r3, #0x5000
	add r3, r3, #2
	strh r3, [r4]
	bl FUN_08248bd8
_08248920:
	.byte 0x00, 0x00, 0x96, 0xE5, 0xB2, 0x31, 0xD0, 0xE1, 0x03, 0x00, 0x53, 0xE3, 0x08, 0x00, 0x00, 0x1A
	.byte 0xBC, 0x00, 0x00, 0xEB, 0x00, 0x30, 0x96, 0xE5, 0x1C, 0x10, 0x93, 0xE5, 0x00, 0x00, 0x51, 0xE3
	.byte 0x44, 0x00, 0x00, 0x0A, 0x7B, 0x0F, 0xA0, 0xE3, 0x02, 0x00, 0x80, 0xE2, 0xD9, 0x00, 0x00, 0xEB
	.byte 0x40, 0x00, 0x00, 0xEA, 0x12, 0x3E, 0xA0, 0xE3, 0x01, 0x33, 0x83, 0xE2, 0x00, 0x10, 0xA0, 0xE3
	.byte 0x00, 0x10, 0x83, 0xE5, 0x05, 0x2A, 0xA0, 0xE3, 0xB0, 0x10, 0xC4, 0xE1, 0x03, 0x20, 0x82, 0xE2
	.byte 0xB0, 0x20, 0xC4, 0xE1, 0x01, 0x30, 0xA0, 0xE3, 0x14, 0x30, 0xC0, 0xE5, 0x00, 0x00, 0x95, 0xE5
	.byte 0x1C, 0x20, 0x90, 0xE5, 0x00, 0x10, 0x80, 0xE5, 0x01, 0x00, 0x52, 0xE1, 0x31, 0x00, 0x00, 0x0A
	.byte 0x04, 0x30, 0xD0, 0xE5, 0x06, 0x00, 0xD0, 0xE5, 0x02, 0x10, 0xA0, 0xE1, 0x03, 0x04, 0x80, 0xE1
	.byte 0xC4, 0x00, 0x00, 0xEB, 0x2B, 0x00, 0x00, 0xEA
_082489A8:
	mov r3, #0x208
	add r3, r3, #0x4000000
	mov r2, #0
	strh r2, [r3]
	mov r1, #0x100
	add r2, r1, #0x4000002
	ldrh r3, [r2]
	tst r3, #0x80
	beq _08248A2C
	ldrh r3, [r2]
	tst r3, #3
	bne _08248A08
	mov r2, #0xff00
	add r1, r1, #0x4000000
	ldrh r3, [r1]
	add r2, r2, #0x9b
	cmp r3, r2
	bls _08248A2C
_082489F0:
	ldrh r3, [r1]
	cmp r3, r2
	bhi _082489F0
	b _08248A2C
	.align 2, 0
_08248A00: .4byte 0x030057D0
_08248A04: .4byte 0x996601EE
_08248A08:
	mov r2, #0xff00
	add r1, r1, #0x4000000
	ldrh r3, [r1]
	add r2, r2, #0xfe
	cmp r3, r2
	bls _08248A2C
_08248A20:
	ldrh r3, [r1]
	cmp r3, r2
	bhi _08248A20
_08248A2C:
	mov r1, #0x128
	add r1, r1, #0x4000000
	mov r0, #0x208
	add r0, r0, #0x4000000
	mov r3, #0x5000
	add r2, r3, #2
	strh r2, [r1]
	add r3, r3, #0x82
	strh r3, [r1]
	mov r2, #1
	strh r2, [r0]
_08248A58:
	ldmdb fp, {r4, r5, r6, fp, sp, lr}
	bx lr

	arm_func_start FUN_08248a60
FUN_08248a60: @ 0x08248A60
	mov ip, sp
	push {fp, ip, lr, pc}
	mov r1, #0x128
	add r1, r1, #0x4000000
	lsl r0, r0, #0x10
	ldr r2, _08248AC4 @ =0x030057D0
	sub fp, ip, #4
	lsr lr, r0, #0xe
	ldr ip, [r2]
_08248A84:
	ldrb r3, [ip, #0x10]
	and r0, r3, #0xff
	cmp r0, #1
	beq _08248AB0
	ldrh r3, [r1]
	and r3, r3, #4
	cmp r3, lr
	bne _08248A84
	mov r0, #0
	ldmdb fp, {fp, sp, lr}
	bx lr
_08248AB0:
	ldr r2, [r2]
	mov r3, #0
	strb r3, [r2, #0x10]
	ldmdb fp, {fp, sp, lr}
	bx lr
	.align 2, 0
_08248AC4: .4byte 0x030057D0

	arm_func_start FUN_08248ac8
FUN_08248ac8: @ 0x08248AC8
	mov ip, sp
	push {r4, r5, fp, ip, lr, pc}
	mov r1, #0x208
	add r1, r1, #0x4000000
	mov r3, #0
	sub fp, ip, #4
	ldr ip, _08248B80 @ =0x030057D0
	and lr, r0, #0xff
	ldr r2, [ip]
	cmp lr, #0x50
	ldrb r0, [r2, #0xa]
	mov r4, ip
	mov r2, lr
	strh r3, [r1]
	lsl r0, r0, #2
	add r3, r3, #0x100
	add r1, r3, #0x4000000
	add r3, r3, #0x4000002
	add r5, r0, r3
	beq _08248B50
	bgt _08248B28
	cmp lr, #0x32
	beq _08248B3C
	b _08248B9C
_08248B28:
	cmp r2, #0x64
	beq _08248B68
	cmp r2, #0x82
	beq _08248B84
	b _08248B9C
_08248B3C:
	mvn r3, #0x334
	strh r3, [r0, r1]
	ldr r2, [r4]
	mov r3, #1
	b _08248B98
_08248B50:
	mov r3, #-0x52000000
	asr r3, r3, #0x14
	strh r3, [r0, r1]
	ldr r2, [r4]
	mov r3, #2
	b _08248B98
_08248B68:
	mvn r3, #0x660
	sub r3, r3, #9
	strh r3, [r0, r1]
	ldr r2, [r4]
	mov r3, #3
	b _08248B98
	.align 2, 0
_08248B80: .4byte 0x030057D0
_08248B84:
	mvn r3, #0x850
	sub r3, r3, #2
	strh r3, [r0, r1]
	ldr r2, [r4]
	mov r3, #4
_08248B98:
	str r3, [r2, #0xc]
_08248B9C:
	mov ip, #0x200
	add ip, ip, #0x4000002
	mov r3, #0xc3
	strh r3, [r5]
	mov r1, #0x208
	ldr r2, [r4]
	add r1, r1, #0x4000000
	ldrb r0, [r2, #0xa]
	sub r3, r3, #0xbb
	lsl r3, r3, r0
	strh r3, [ip]
	mov r2, #1
	strh r2, [r1]
	ldmdb fp, {r4, r5, fp, sp, lr}
	bx lr
FUN_08248bd8:
	mov ip, sp
	push {fp, ip, lr, pc}
	mov r1, #0x100
	ldr lr, _08248C24 @ =0x030057D0
	add r0, r1, #0x4000000
	ldr r2, [lr]
	sub fp, ip, #4
	ldrb r3, [r2, #0xa]
	mov ip, #0
	str ip, [r2, #0xc]
	lsl r3, r3, #2
	strh ip, [r3, r0]
	ldr r2, [lr]
	ldrb r3, [r2, #0xa]
	add r1, r1, #0x4000002
	lsl r3, r3, #2
	strh ip, [r3, r1]
	ldmdb fp, {fp, sp, lr}
	bx lr
	.align 2, 0
_08248C24: .4byte 0x030057D0

	arm_func_start FUN_08248c28
FUN_08248c28: @ 0x08248C28
	mov ip, sp
	push {fp, ip, lr, pc}
	ldr r0, _08248CB0 @ =0x030057D0
	ldr r2, [r0]
	mov r3, #5
	str r3, [r2]
	mov r1, #0
	strb r1, [r2, #0x14]
	ldr r3, [r0]
	strb r1, [r3, #4]
	ldr r2, [r0]
	strb r1, [r2, #5]
	ldr r3, [r0]
	strb r1, [r3, #6]
	ldr r2, [r0]
	strb r1, [r2, #7]
	ldr r3, [r0]
	strb r1, [r3, #8]
	ldr r2, [r0]
	strb r1, [r2, #9]
	ldr r3, [r0]
	str r1, [r3, #0xc]
	sub fp, ip, #4
	strb r1, [r3, #0x10]
	mov r2, #0x128
	ldr ip, [r0]
	add r2, r2, #0x4000000
	strh r1, [ip, #0x12]
	mov r3, #0x5000
	strb r1, [ip, #0x15]
	add r3, r3, #0x82
	strh r3, [r2]
	ldmdb fp, {fp, sp, lr}
	bx lr
	.align 2, 0
_08248CB0: .4byte 0x030057D0

	arm_func_start FUN_08248cb4
FUN_08248cb4: @ 0x08248CB4
	bx r2

	arm_func_start FUN_08248cb8
FUN_08248cb8: @ 0x08248CB8
	bx r1

	arm_func_start FUN_08248cbc
FUN_08248cbc: @ 0x08248CBC
	bx r0

	thumb_func_start FUN_08248cc0
FUN_08248cc0: @ 0x08248CC0
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	mov ip, r2
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	lsls r3, r3, #0x18
	lsrs r7, r3, #0x18
	movs r0, #0xf0
	lsls r0, r0, #0x14
	ands r0, r4
	movs r1, #0x80
	lsls r1, r1, #0x12
	cmp r0, r1
	bne _08248CE0
	cmp r7, #0
	bne _08248CE8
_08248CE0:
	movs r0, #3
	ands r0, r4
	cmp r0, #0
	beq _08248CEC
_08248CE8:
	movs r0, #2
	b _08248DD6
_08248CEC:
	cmp r7, #0
	beq _08248CF8
	ldr r3, _08248CF4 @ =0x00000E64
	b _08248CFA
	.align 2, 0
_08248CF4: .4byte 0x00000E64
_08248CF8:
	ldr r3, _08248D04 @ =0x00000504
_08248CFA:
	cmp r2, r3
	bhs _08248D08
	movs r0, #1
	b _08248DD6
	.align 2, 0
_08248D04: .4byte 0x00000504
_08248D08:
	ldr r0, _08248DDC @ =0x03005800
	str r4, [r0]
	ldr r1, _08248DE0 @ =0x03005804
	adds r0, r4, #0
	adds r0, #0xb4
	str r0, [r1]
	ldr r1, _08248DE4 @ =0x03005808
	adds r0, #0x28
	str r0, [r1]
	ldr r2, _08248DE8 @ =0x030057F0
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r4, r1
	str r0, [r2]
	ldr r1, _08248DEC @ =0x030057E0
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r4, r3
	str r0, [r1]
	movs r5, #1
	adds r6, r2, #0
	adds r4, r1, #0
_08248D34:
	lsls r2, r5, #2
	adds r3, r2, r6
	subs r1, r5, #1
	lsls r1, r1, #2
	adds r0, r1, r6
	ldr r0, [r0]
	adds r0, #0x70
	str r0, [r3]
	adds r2, r2, r4
	adds r1, r1, r4
	ldr r0, [r1]
	adds r0, #0x1c
	str r0, [r2]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #3
	bls _08248D34
	ldr r0, _08248DE4 @ =0x03005808
	ldr r1, [r0]
	adds r1, #0xdc
	ldr r4, _08248DEC @ =0x030057E0
	ldr r0, [r4, #0xc]
	adds r0, #0x1c
	str r0, [r1]
	mov r1, ip
	adds r2, r7, #0
	bl FUN_08247824
	bl FUN_08248dfc
	movs r5, #0
	ldr r3, _08248DE8 @ =0x030057F0
	movs r2, #0
_08248D78:
	lsls r1, r5, #2
	adds r0, r1, r3
	ldr r0, [r0]
	str r2, [r0, #0x68]
	str r2, [r0, #0x6c]
	adds r1, r1, r4
	ldr r0, [r1]
	str r2, [r0, #0x14]
	str r2, [r0, #0x18]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #3
	bls _08248D78
	ldr r1, _08248DF0 @ =0x0824A235
	movs r5, #2
	rsbs r5, r5, #0
	ands r5, r1
	ldr r2, _08248DE4 @ =0x03005808
	ldr r0, [r2]
	adds r4, r0, #0
	adds r4, #8
	ldr r0, _08248DF4 @ =FUN_0824a264
	subs r0, r0, r1
	lsls r0, r0, #0xf
	lsrs r3, r0, #0x10
	subs r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	ldr r0, _08248DF8 @ =0x0000FFFF
	cmp r3, r0
	beq _08248DCC
	adds r6, r0, #0
_08248DBA:
	ldrh r0, [r5]
	strh r0, [r4]
	adds r5, #2
	adds r4, #2
	subs r0, r3, #1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, r6
	bne _08248DBA
_08248DCC:
	ldr r1, [r2]
	adds r0, r1, #0
	adds r0, #9
	str r0, [r1, #4]
	movs r0, #0
_08248DD6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08248DDC: .4byte 0x03005800
_08248DE0: .4byte 0x03005804
_08248DE4: .4byte 0x03005808
_08248DE8: .4byte 0x030057F0
_08248DEC: .4byte 0x030057E0
_08248DF0: .4byte 0x0824A235
_08248DF4: .4byte FUN_0824a264
_08248DF8: .4byte 0x0000FFFF

	thumb_func_start FUN_08248dfc
FUN_08248dfc: @ 0x08248DFC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r1, _08248E70 @ =0x04000208
	ldrh r0, [r1]
	adds r7, r0, #0
	movs r6, #0
	strh r6, [r1]
	ldr r5, _08248E74 @ =0x03005804
	ldr r1, [r5]
	ldrb r4, [r1]
	mov r0, sp
	strh r6, [r0]
	ldr r2, _08248E78 @ =0x01000014
	bl CpuSet
	ldr r2, [r5]
	movs r0, #8
	ands r4, r0
	movs r1, #0
	strb r4, [r2]
	mov r0, sp
	adds r0, #2
	strh r1, [r0]
	ldr r4, _08248E7C @ =0x03005800
	ldr r1, [r4]
	ldr r2, _08248E80 @ =0x0100005A
	bl CpuSet
	ldr r1, [r4]
	movs r0, #4
	strb r0, [r1, #9]
	ldr r0, [r5]
	strb r6, [r0, #6]
	ldr r1, [r4]
	movs r0, #0xff
	strb r0, [r1]
	bl FUN_0824a2c8
	ldr r0, [r5]
	strb r6, [r0, #9]
	movs r2, #0
	movs r3, #0
_08248E50:
	ldr r0, [r5]
	lsls r1, r2, #1
	adds r0, #0x12
	adds r0, r0, r1
	strh r3, [r0]
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _08248E50
	ldr r0, _08248E70 @ =0x04000208
	strh r7, [r0]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08248E70: .4byte 0x04000208
_08248E74: .4byte 0x03005804
_08248E78: .4byte 0x01000014
_08248E7C: .4byte 0x03005800
_08248E80: .4byte 0x0100005A

	thumb_func_start FUN_08248e84
FUN_08248e84: @ 0x08248E84
	push {lr}
	ldr r0, _08248E94 @ =FUN_08248f58
	bl FUN_08247a78
	bl FUN_08247eec
	pop {r0}
	bx r0
	.align 2, 0
_08248E94: .4byte FUN_08248f58

	thumb_func_start FUN_08248e98
FUN_08248e98: @ 0x08248E98
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0
	strb r0, [r4]
	ldr r5, _08248EB0 @ =0x03005800
	ldr r0, [r5]
	ldrb r0, [r0]
	cmp r0, #1
	beq _08248EB4
	movs r0, #0xc0
	lsls r0, r0, #2
	b _08248EDA
	.align 2, 0
_08248EB0: .4byte 0x03005800
_08248EB4:
	bl FUN_08248ef4
	adds r1, r0, #0
	ldrb r0, [r1]
	cmp r0, #0x28
	beq _08248EC4
	cmp r0, #0x36
	bne _08248ED8
_08248EC4:
	ldrb r0, [r1, #1]
	cmp r0, #0
	bne _08248ED0
	ldr r0, [r5]
	ldrb r0, [r0, #2]
	b _08248ED2
_08248ED0:
	ldrb r0, [r1, #4]
_08248ED2:
	strb r0, [r4]
	movs r0, #0
	b _08248EDA
_08248ED8:
	movs r0, #0x10
_08248EDA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08248ee0
FUN_08248ee0: @ 0x08248EE0
	push {lr}
	adds r2, r0, #0
	adds r0, r1, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r1, r2, #0
	bl FUN_082478fc
	pop {r0}
	bx r0

	thumb_func_start FUN_08248ef4
FUN_08248ef4: @ 0x08248EF4
	ldr r0, _08248F00 @ =0x03005808
	ldr r0, [r0]
	adds r0, #0xdc
	ldr r0, [r0]
	bx lr
	.align 2, 0
_08248F00: .4byte 0x03005808

	thumb_func_start FUN_08248f04
FUN_08248f04: @ 0x08248F04
	push {lr}
	bl FUN_08247a84
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08248f10
FUN_08248f10: @ 0x08248F10
	push {lr}
	adds r1, r0, #0
	ldr r0, _08248F28 @ =0x03005808
	ldr r0, [r0]
	str r1, [r0]
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r0, r0, #0x1f
	bl FUN_08248f2c
	pop {r0}
	bx r0
	.align 2, 0
_08248F28: .4byte 0x03005808

	thumb_func_start FUN_08248f2c
FUN_08248f2c: @ 0x08248F2C
	push {lr}
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08248F44
	ldr r0, _08248F40 @ =0x03005804
	ldr r2, [r0]
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	b _08248F4E
	.align 2, 0
_08248F40: .4byte 0x03005804
_08248F44:
	ldr r0, _08248F54 @ =0x03005804
	ldr r2, [r0]
	ldrb r1, [r2]
	movs r0, #0xf7
	ands r0, r1
_08248F4E:
	strb r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0
_08248F54: .4byte 0x03005804

	thumb_func_start FUN_08248f58
FUN_08248f58: @ 0x08248F58
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r0, _08248F8C @ =0x08248F99
	bl FUN_08247a78
	ldr r0, _08248F90 @ =0x03005804
	ldr r0, [r0]
	strh r4, [r0, #0x1c]
	ldrb r1, [r0]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08248F86
	ldr r0, _08248F94 @ =0x03005808
	ldr r0, [r0]
	ldr r2, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl _call_via_r2
_08248F86:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08248F8C: .4byte 0x08248F99
_08248F90: .4byte 0x03005804
_08248F94: .4byte 0x03005808
_08248F98:
	.byte 0x30, 0xB5, 0x00, 0x06, 0x00, 0x0E, 0x09, 0x04
	.byte 0x0B, 0x0C, 0xFF, 0x28, 0x26, 0xD1, 0x15, 0x48, 0x00, 0x68, 0x01, 0x78, 0x08, 0x20, 0x08, 0x40
	.byte 0x00, 0x28, 0x06, 0xD0, 0x12, 0x48, 0x00, 0x68, 0x02, 0x68, 0xFF, 0x20, 0x19, 0x1C, 0x03, 0xF0
	.byte 0x53, 0xFF, 0x10, 0x48, 0x00, 0x68, 0x81, 0x78, 0xC0, 0x78, 0x05, 0x1C, 0x0D, 0x43, 0x00, 0x24
	.byte 0x28, 0x1C, 0x20, 0x41, 0x01, 0x21, 0x08, 0x40, 0x00, 0x28, 0x02, 0xD0, 0x20, 0x1C, 0x00, 0xF0
	.byte 0x6D, 0xFF, 0x60, 0x1C, 0x00, 0x06, 0x04, 0x0E, 0x03, 0x2C, 0xF1, 0xD9, 0x05, 0x48, 0x01, 0x68
	.byte 0xFF, 0x20, 0x08, 0x70, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00, 0x04, 0x58, 0x00, 0x03
	.byte 0x08, 0x58, 0x00, 0x03, 0x00, 0x58, 0x00, 0x03

	thumb_func_start FUN_08249008
FUN_08249008: @ 0x08249008
	push {lr}
	bl FUN_08247a9c
	ldr r0, _08249018 @ =0x03005804
	ldr r0, [r0]
	ldrh r0, [r0, #0x1c]
	pop {r1}
	bx r1
	.align 2, 0
_08249018: .4byte 0x03005804

	thumb_func_start FUN_0824901c
FUN_0824901c: @ 0x0824901C
	push {lr}
	ldr r0, _0824902C @ =FUN_08248f58
	bl FUN_08247a78
	bl FUN_08247b30
	pop {r0}
	bx r0
	.align 2, 0
_0824902C: .4byte FUN_08248f58

	thumb_func_start FUN_08249030
FUN_08249030: @ 0x08249030
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r5, _08249048 @ =0x03005808
	ldr r0, [r5]
	adds r0, #0xdc
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0x93
	beq _0824904C
	movs r0, #0x10
	b _08249066
	.align 2, 0
_08249048: .4byte 0x03005808
_0824904C:
	bl FUN_08247a9c
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08249060
	ldr r0, [r5]
	adds r0, #0xdc
	ldr r0, [r0]
	ldrb r0, [r0, #7]
	b _08249062
_08249060:
	movs r0, #0xff
_08249062:
	strb r0, [r4]
	movs r0, #0
_08249066:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0824906c
FUN_0824906c: @ 0x0824906C
	push {lr}
	ldr r2, _08249074 @ =0x085A8B0C
	ldr r3, _08249078 @ =0x030000F0
	b _08249086
	.align 2, 0
_08249074: .4byte 0x085A8B0C
_08249078: .4byte 0x030000F0
_0824907C:
	ldrb r0, [r3]
	adds r3, #1
	adds r2, #1
	cmp r1, r0
	bne _082490DC
_08249086:
	ldrb r1, [r2]
	cmp r1, #0
	bne _0824907C
	movs r2, #0xc0
	lsls r2, r2, #0x12
	movs r3, #0
	movs r1, #0
_08249094:
	ldrh r0, [r2]
	adds r0, r3, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	adds r2, #2
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x59
	bls _08249094
	ldr r0, _082490D0 @ =0x030000FA
	ldrh r0, [r0]
	cmp r3, r0
	bne _082490DC
	movs r0, #0xc0
	lsls r0, r0, #0x12
	ldr r1, _082490D4 @ =0x03005800
	ldr r1, [r1]
	movs r2, #0x5a
	bl CpuSet
	ldr r0, _082490D8 @ =0x03005804
	ldr r2, [r0]
	ldrb r1, [r2]
	movs r0, #0x80
	orrs r0, r1
	strb r0, [r2]
	movs r0, #0
	b _082490DE
	.align 2, 0
_082490D0: .4byte 0x030000FA
_082490D4: .4byte 0x03005800
_082490D8: .4byte 0x03005804
_082490DC:
	movs r0, #1
_082490DE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082490e4
FUN_082490e4: @ 0x082490E4
	push {lr}
	ldr r0, _08249104 @ =0x04000208
	ldrh r0, [r0]
	cmp r0, #0
	bne _0824910C
	movs r0, #0x3d
	movs r1, #6
	bl FUN_08248f58
	ldr r0, _08249108 @ =0x030057D0
	ldr r1, [r0]
	ldrh r0, [r1, #0x12]
	movs r0, #6
	strh r0, [r1, #0x12]
	b _08249182
	.align 2, 0
_08249104: .4byte 0x04000208
_08249108: .4byte 0x030057D0
_0824910C:
	bl FUN_08247938
	bl FUN_08248dfc
	movs r0, #8
	bl FUN_0824bbac
	ldr r1, _0824915C @ =0x00008001
	cmp r0, r1
	bne _08249170
	ldr r0, _08249160 @ =0x030057D0
	ldr r0, [r0]
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #2
	ldr r2, _08249164 @ =0x04000100
	adds r1, r0, r2
	movs r0, #0
	str r0, [r1]
	movs r0, #0x83
	lsls r0, r0, #0x10
	str r0, [r1]
	ldr r0, [r1]
	lsls r0, r0, #0x10
	ldr r2, _08249168 @ =0x0105FFFF
	ldr r3, _0824916C @ =0x0824918D
	cmp r0, r2
	bhi _0824914A
_08249142:
	ldr r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, r2
	bls _08249142
_0824914A:
	movs r0, #0
	str r0, [r1]
	adds r0, r3, #0
	bl FUN_08247a78
	bl FUN_08247ffc
	b _08249182
	.align 2, 0
_0824915C: .4byte 0x00008001
_08249160: .4byte 0x030057D0
_08249164: .4byte 0x04000100
_08249168: .4byte 0x0105FFFF
_0824916C: .4byte 0x0824918D
_08249170:
	ldr r1, _08249188 @ =0x04000128
	movs r2, #0x80
	lsls r2, r2, #6
	adds r0, r2, #0
	strh r0, [r1]
	movs r0, #0x3d
	movs r1, #0
	bl FUN_08248f58
_08249182:
	pop {r0}
	bx r0
	.align 2, 0
_08249188: .4byte 0x04000128
_0824918C:
	.byte 0x10, 0xB5, 0x00, 0x06
	.byte 0x03, 0x0E, 0x09, 0x04, 0x09, 0x0C, 0x0A, 0x1C, 0x00, 0x2A, 0x04, 0xD1, 0x05, 0x49, 0x80, 0x24
	.byte 0xA4, 0x01, 0x20, 0x1C, 0x08, 0x80, 0x18, 0x1C, 0x11, 0x1C, 0xFF, 0xF7, 0xD5, 0xFE, 0x10, 0xBC
	.byte 0x01, 0xBC, 0x00, 0x47, 0x28, 0x01, 0x00, 0x04

	thumb_func_start FUN_082491b8
FUN_082491b8: @ 0x082491B8
	push {lr}
	ldr r0, _082491C8 @ =0x04000208
	ldrh r0, [r0]
	cmp r0, #0
	bne _082491CC
	movs r0, #1
	rsbs r0, r0, #0
	b _082491EC
	.align 2, 0
_082491C8: .4byte 0x04000208
_082491CC:
	bl FUN_08247938
	bl FUN_08248dfc
	movs r0, #0x1e
	bl FUN_0824bbac
	adds r2, r0, #0
	cmp r2, #0
	bne _082491EA
	ldr r1, _082491F0 @ =0x04000128
	movs r3, #0x80
	lsls r3, r3, #6
	adds r0, r3, #0
	strh r0, [r1]
_082491EA:
	adds r0, r2, #0
_082491EC:
	pop {r1}
	bx r1
	.align 2, 0
_082491F0: .4byte 0x04000128

	thumb_func_start FUN_082491f4
FUN_082491f4: @ 0x082491F4
	push {lr}
	ldr r0, _08249204 @ =0x08249209
	bl FUN_08247a78
	bl FUN_08247ac4
	pop {r0}
	bx r0
	.align 2, 0
_08249204: .4byte 0x08249209
_08249208:
	.byte 0x30, 0xB5, 0x00, 0x06, 0x05, 0x0E, 0x09, 0x04
	.byte 0x09, 0x0C, 0x0C, 0x1C, 0x00, 0x2C, 0x01, 0xD1, 0xFF, 0xF7, 0xF0, 0xFD, 0x28, 0x1C, 0x21, 0x1C
	.byte 0xFF, 0xF7, 0x9A, 0xFE, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00

	thumb_func_start FUN_0824922c
FUN_0824922c: @ 0x0824922C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	ldr r0, _08249264 @ =FUN_08248f58
	bl FUN_08247a78
	movs r0, #3
	ands r4, r0
	movs r0, #0x3c
	orrs r4, r0
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_08247bf4
	cmp r6, #0
	bne _0824926C
	ldr r0, _08249268 @ =0x03005804
	ldr r1, [r0]
	movs r0, #1
	strh r0, [r1, #0x1a]
	b _08249286
	.align 2, 0
_08249264: .4byte FUN_08248f58
_08249268: .4byte 0x03005804
_0824926C:
	ldr r5, _0824928C @ =0x04000208
	ldrh r4, [r5]
	movs r0, #0
	strh r0, [r5]
	movs r0, #0x96
	lsls r0, r0, #2
	adds r1, r6, #0
	bl Div
	ldr r1, _08249290 @ =0x03005804
	ldr r1, [r1]
	strh r0, [r1, #0x1a]
	strh r4, [r5]
_08249286:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0824928C: .4byte 0x04000208
_08249290: .4byte 0x03005804

	thumb_func_start FUN_08249294
FUN_08249294: @ 0x08249294
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r4, r2, #0
	adds r7, r3, #0
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r2, r1, #0x10
	adds r5, r4, #0
	mov r0, sp
	strb r1, [r0]
	lsrs r2, r2, #0x18
	strb r2, [r0, #1]
	cmp r6, #0
	beq _082492BA
	movs r1, #0x80
	orrs r2, r1
	movs r1, #0
	orrs r2, r1
	strb r2, [r0, #1]
_082492BA:
	movs r2, #2
	ldr r0, _0824931C @ =0x08249321
	mov ip, r0
_082492C0:
	mov r3, sp
	adds r1, r3, r2
	ldrb r0, [r4]
	strb r0, [r1]
	adds r4, #1
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0xe
	bls _082492C0
	movs r3, #0
	adds r1, r7, #0
	movs r2, #0
_082492DA:
	ldrb r0, [r1]
	adds r0, r3, r0
	lsls r0, r0, #0x18
	adds r1, #1
	lsrs r0, r0, #0x18
	ldrb r3, [r5]
	adds r0, r0, r3
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r5, #1
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #7
	bls _082492DA
	mov r1, sp
	mvns r0, r3
	strb r0, [r1, #0xf]
	cmp r6, #0
	beq _08249306
	movs r0, #0
	strb r0, [r1, #0xe]
_08249306:
	mov r0, ip
	bl FUN_08247a78
	mov r0, sp
	adds r1, r7, #0
	bl FUN_08247b9c
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0824931C: .4byte 0x08249321
_08249320:
	.byte 0xF0, 0xB5, 0x00, 0x06, 0x00, 0x0E, 0x84, 0x46, 0x09, 0x04, 0x0F, 0x0C, 0x00, 0x2F, 0x3C, 0xD1
	.byte 0x0C, 0x48, 0x00, 0x68, 0x41, 0x6A, 0x0C, 0x48, 0x06, 0x68, 0x0A, 0x79, 0x35, 0x1C, 0x98, 0x35
	.byte 0x2A, 0x80, 0x48, 0x79, 0x03, 0x02, 0x13, 0x43, 0x2B, 0x80, 0x8C, 0x1D, 0x80, 0x21, 0x09, 0x02
	.byte 0x18, 0x1C, 0x08, 0x40, 0x00, 0x28, 0x09, 0xD0, 0x4B, 0x40, 0x2B, 0x80, 0x31, 0x1C, 0x97, 0x31
	.byte 0x01, 0x20, 0x06, 0xE0, 0xD0, 0x57, 0x00, 0x03, 0x00, 0x58, 0x00, 0x03, 0x31, 0x1C, 0x97, 0x31
	.byte 0x00, 0x20, 0x08, 0x70, 0x00, 0x22, 0x10, 0x4B, 0x18, 0x68, 0x9A, 0x30, 0x80, 0x18, 0x21, 0x78
	.byte 0x01, 0x70, 0x01, 0x34, 0x50, 0x1C, 0x00, 0x06, 0x02, 0x0E, 0x0C, 0x2A, 0xF4, 0xD9, 0x01, 0x34
	.byte 0x00, 0x22, 0x09, 0x4B, 0x18, 0x68, 0xA9, 0x30, 0x80, 0x18, 0x21, 0x78, 0x01, 0x70, 0x01, 0x34
	.byte 0x50, 0x1C, 0x00, 0x06, 0x02, 0x0E, 0x07, 0x2A, 0xF4, 0xD9, 0x60, 0x46, 0x39, 0x1C, 0xFF, 0xF7
	.byte 0xD3, 0xFD, 0xF0, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x58, 0x00, 0x03

	thumb_func_start FUN_082493bc
FUN_082493bc: @ 0x082493BC
	push {lr}
	ldr r0, _082493EC @ =0x08248F99
	bl FUN_08247a78
	bl FUN_08247b30
	bl FUN_08247a9c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _082493F4
	ldr r0, _082493F0 @ =0x03005808
	ldr r0, [r0]
	adds r0, #0xdc
	ldr r0, [r0]
	ldrb r0, [r0, #7]
	cmp r0, #0
	bne _082493FA
	movs r0, #1
	bl FUN_08249434
	b _082493FA
	.align 2, 0
_082493EC: .4byte 0x08248F99
_082493F0: .4byte 0x03005808
_082493F4:
	movs r0, #0x19
	bl FUN_08248f58
_082493FA:
	ldr r0, _08249408 @ =0x0824940D
	bl FUN_08247a78
	bl FUN_08247c34
	pop {r0}
	bx r0
	.align 2, 0
_08249408: .4byte 0x0824940D
_0824940C:
	.byte 0x00, 0xB5, 0x00, 0x06
	.byte 0x03, 0x0E, 0x09, 0x04, 0x09, 0x0C, 0x0A, 0x1C, 0x00, 0x2A, 0x03, 0xD1, 0x04, 0x48, 0x01, 0x68
	.byte 0x01, 0x20, 0x48, 0x72, 0x18, 0x1C, 0x11, 0x1C, 0xFF, 0xF7, 0x96, 0xFD, 0x01, 0xBC, 0x00, 0x47
	.byte 0x04, 0x58, 0x00, 0x03

	thumb_func_start FUN_08249434
FUN_08249434: @ 0x08249434
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl FUN_0824a2c8
	cmp r4, #0
	beq _0824945C
	mov r0, sp
	movs r5, #0
	strh r5, [r0]
	ldr r4, _08249490 @ =0x03005800
	ldr r1, [r4]
	adds r1, #0x14
	ldr r2, _08249494 @ =0x01000040
	bl CpuSet
	ldr r0, [r4]
	strb r5, [r0, #8]
_0824945C:
	movs r1, #0
	ldr r2, _08249490 @ =0x03005800
	adds r4, r2, #0
	movs r3, #0
_08249464:
	ldr r0, [r4]
	adds r0, #0xa
	adds r0, r0, r1
	strb r3, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls _08249464
	ldr r0, [r2]
	movs r1, #0
	strb r1, [r0, #1]
	ldr r0, [r2]
	strb r1, [r0, #2]
	ldr r0, [r2]
	strb r1, [r0, #3]
	ldr r0, [r2]
	strb r1, [r0, #7]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08249490: .4byte 0x03005800
_08249494: .4byte 0x01000040

	thumb_func_start FUN_08249498
FUN_08249498: @ 0x08249498
	push {lr}
	ldr r0, _082494A8 @ =0x082494C1
	bl FUN_08247a78
	bl FUN_08247c58
	pop {r0}
	bx r0
	.align 2, 0
_082494A8: .4byte 0x082494C1

	thumb_func_start FUN_082494ac
FUN_082494ac: @ 0x082494AC
	push {lr}
	ldr r0, _082494BC @ =0x082494C1
	bl FUN_08247a78
	bl FUN_08247c7c
	pop {r0}
	bx r0
	.align 2, 0
_082494BC: .4byte 0x082494C1
_082494C0:
	.byte 0x70, 0xB5, 0x00, 0x06, 0x04, 0x0E, 0x09, 0x04, 0x0E, 0x0C, 0x00, 0x2E, 0x01, 0xD1, 0x00, 0xF0
	.byte 0x3B, 0xF8, 0x1A, 0x2C, 0x1E, 0xD1, 0x0C, 0x4D, 0x28, 0x68, 0x94, 0x30, 0x00, 0x88, 0x00, 0x28
	.byte 0x26, 0xD1, 0x0A, 0x48, 0xFE, 0xF7, 0xC8, 0xFA, 0xFE, 0xF7, 0x22, 0xFB, 0xFE, 0xF7, 0xD6, 0xFA
	.byte 0x00, 0x04, 0x00, 0x28, 0x1C, 0xD1, 0x29, 0x68, 0x05, 0x48, 0x00, 0x68, 0xDC, 0x30, 0x00, 0x68
	.byte 0x80, 0x88, 0x94, 0x31, 0x08, 0x80, 0x13, 0xE0, 0x00, 0x58, 0x00, 0x03, 0x99, 0x8F, 0x24, 0x08
	.byte 0x08, 0x58, 0x00, 0x03, 0x1B, 0x2C, 0x0B, 0xD1, 0x09, 0x48, 0x01, 0x68, 0x08, 0x78, 0xFF, 0x28
	.byte 0x02, 0xD1, 0x94, 0x31, 0x00, 0x20, 0x08, 0x80, 0x06, 0x48, 0x01, 0x68, 0x00, 0x20, 0x48, 0x72
	.byte 0x20, 0x1C, 0x31, 0x1C, 0xFF, 0xF7, 0x10, 0xFD, 0x70, 0xBC, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
	.byte 0x00, 0x58, 0x00, 0x03, 0x04, 0x58, 0x00, 0x03

	thumb_func_start FUN_08249548
FUN_08249548: @ 0x08249548
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r1, _08249674 @ =0x03005808
	ldr r0, [r1]
	adds r0, #0xdc
	ldr r0, [r0]
	ldrb r2, [r0, #1]
	mov r8, r2
	adds r4, r1, #0
	cmp r2, #0
	beq _082495A6
	ldr r5, [r0, #4]
	ldr r0, _08249678 @ =0x08248F99
	bl FUN_08247a78
	bl FUN_08247ae8
	bl FUN_08247a9c
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0824959A
	ldr r0, [r4]
	adds r0, #0xdc
	ldr r0, [r0]
	adds r4, r0, #4
	movs r2, #0
_08249586:
	mov r0, sp
	adds r1, r0, r2
	ldrb r0, [r4]
	strb r0, [r1]
	adds r4, #1
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _08249586
_0824959A:
	ldr r0, _08249674 @ =0x03005808
	ldr r1, [r0]
	adds r1, #0xdc
	ldr r1, [r1]
	str r5, [r1, #4]
	adds r4, r0, #0
_082495A6:
	ldr r0, [r4]
	adds r0, #0xdc
	ldr r0, [r0]
	adds r4, r0, #4
	mov r1, r8
	cmp r1, #0
	beq _08249662
	ldr r2, _0824967C @ =0x03005804
	mov sb, r2
	ldr r7, _08249680 @ =0x03005800
	mov sl, sb
_082495BC:
	ldrb r2, [r4, #2]
	adds r5, r2, #0
	cmp r2, #3
	bhi _08249652
	ldr r1, [r7]
	ldrb r0, [r1, #2]
	asrs r0, r2
	movs r6, #1
	ands r0, r6
	cmp r0, #0
	bne _08249652
	ldrb r3, [r1, #3]
	asrs r3, r2
	ands r3, r6
	cmp r3, #0
	bne _08249652
	mov r1, sp
	adds r0, r1, r2
	ldrb r0, [r0]
	mov ip, sl
	cmp r0, #0
	beq _082495F6
	mov r0, sb
	ldr r1, [r0]
	adds r1, #0xe
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_082495F6:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #0xe
	adds r1, r0, r5
	ldrb r0, [r1]
	cmp r0, #3
	bls _08249652
	strb r3, [r1]
	ldr r0, [r7]
	adds r0, #0xa
	adds r0, r0, r5
	movs r1, #0xff
	strb r1, [r0]
	ldr r2, [r7]
	adds r0, r6, #0
	lsls r0, r5
	ldrb r1, [r2, #2]
	orrs r0, r1
	strb r0, [r2, #2]
	ldr r1, [r7]
	ldrb r0, [r1, #1]
	adds r0, #1
	strb r0, [r1, #1]
	ldr r1, [r7]
	lsls r3, r5, #5
	adds r1, r1, r3
	ldrh r0, [r4]
	strh r0, [r1, #0x14]
	strb r5, [r1, #0x16]
	ldr r0, [r7]
	strb r6, [r0]
	mov r0, ip
	ldr r2, [r0]
	ldrb r1, [r2]
	movs r0, #0x7f
	ands r0, r1
	strb r0, [r2]
	mov r2, ip
	ldr r1, [r2]
	lsls r0, r5, #1
	adds r1, #0x12
	adds r1, r1, r0
	ldr r0, [r7]
	adds r0, r0, r3
	ldrh r0, [r0, #0x14]
	strh r0, [r1]
_08249652:
	mov r0, r8
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	adds r4, #4
	cmp r0, #0
	bne _082495BC
_08249662:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08249674: .4byte 0x03005808
_08249678: .4byte 0x08248F99
_0824967C: .4byte 0x03005804
_08249680: .4byte 0x03005800

	thumb_func_start FUN_08249684
FUN_08249684: @ 0x08249684
	push {lr}
	ldr r0, _08249694 @ =0x08249699
	bl FUN_08247a78
	bl FUN_08247ca0
	pop {r0}
	bx r0
	.align 2, 0
_08249694: .4byte 0x08249699
_08249698:
	.byte 0x30, 0xB5, 0x00, 0x06, 0x05, 0x0E, 0x09, 0x04
	.byte 0x09, 0x0C, 0x0C, 0x1C, 0x00, 0x2C, 0x02, 0xD1, 0x00, 0x20, 0xFF, 0xF7, 0xC3, 0xFE, 0x28, 0x1C
	.byte 0x21, 0x1C, 0xFF, 0xF7, 0x51, 0xFC, 0x30, 0xBC, 0x01, 0xBC, 0x00, 0x47

	thumb_func_start FUN_082496bc
FUN_082496bc: @ 0x082496BC
	push {lr}
	ldr r0, _082496CC @ =0x082496D1
	bl FUN_08247a78
	bl FUN_08247cc4
	pop {r0}
	bx r0
	.align 2, 0
_082496CC: .4byte 0x082496D1
_082496D0:
	.byte 0x30, 0xB5, 0x00, 0x06, 0x05, 0x0E, 0x09, 0x04, 0x09, 0x0C, 0x0C, 0x1C, 0x00, 0x2C, 0x01, 0xD1
	.byte 0x00, 0xF0, 0x12, 0xF8, 0x28, 0x1C, 0x21, 0x1C, 0xFF, 0xF7, 0x36, 0xFC, 0x30, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00

	thumb_func_start FUN_082496f4
FUN_082496f4: @ 0x082496F4
	push {lr}
	ldr r0, _08249704 @ =FUN_08248f58
	bl FUN_08247a78
	bl FUN_08247ce8
	pop {r0}
	bx r0
	.align 2, 0
_08249704: .4byte FUN_08248f58

	thumb_func_start FUN_08249708
FUN_08249708: @ 0x08249708
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	mov r0, sp
	movs r4, #0
	strh r4, [r0]
	ldr r5, _082497B0 @ =0x03005800
	ldr r1, [r5]
	adds r1, #0x14
	ldr r2, _082497B4 @ =0x01000040
	bl CpuSet
	ldr r0, _082497B8 @ =0x03005808
	ldr r0, [r0]
	adds r0, #0xdc
	ldr r2, [r0]
	ldrb r7, [r2, #1]
	adds r2, #4
	ldr r0, [r5]
	strb r4, [r0, #8]
	movs r6, #0
	cmp r7, #0
	beq _0824980C
	mov ip, r5
	ldr r0, _082497BC @ =0x00007FFF
	mov r8, r0
_0824973E:
	subs r0, r7, #7
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	adds r1, r2, #6
	adds r2, #0x13
	ldrb r0, [r2]
	mvns r0, r0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r2, #1
	movs r4, #0
	movs r3, #0
	adds r6, #1
_08249758:
	ldrb r0, [r2]
	adds r0, r4, r0
	lsls r0, r0, #0x18
	adds r2, #1
	lsrs r0, r0, #0x18
	ldrb r4, [r1]
	adds r0, r0, r4
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r1, #1
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #7
	bls _08249758
	cmp r4, r5
	bne _08249800
	subs r2, #0x1c
	mov r0, ip
	ldr r1, [r0]
	ldrb r0, [r1, #8]
	lsls r0, r0, #5
	adds r0, #0x14
	adds r4, r1, r0
	ldrh r0, [r2]
	movs r3, #0
	strh r0, [r4]
	adds r2, #2
	ldrb r0, [r2]
	strb r0, [r4, #2]
	adds r2, #2
	ldrh r1, [r2]
	mov r0, r8
	ands r0, r1
	strh r0, [r4, #4]
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _082497C0
	movs r0, #1
	strb r0, [r4, #3]
	b _082497C2
	.align 2, 0
_082497B0: .4byte 0x03005800
_082497B4: .4byte 0x01000040
_082497B8: .4byte 0x03005808
_082497BC: .4byte 0x00007FFF
_082497C0:
	strb r3, [r4, #3]
_082497C2:
	adds r2, #2
	movs r3, #0
	adds r5, r4, #0
	adds r5, #0x15
	adds r4, #6
_082497CC:
	adds r1, r4, r3
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, #1
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0xc
	bls _082497CC
	adds r2, #1
	movs r3, #0
	adds r4, r5, #0
_082497E4:
	adds r1, r4, r3
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, #1
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #7
	bls _082497E4
	mov r4, ip
	ldr r1, [r4]
	ldrb r0, [r1, #8]
	adds r0, #1
	strb r0, [r1, #8]
_08249800:
	lsls r0, r6, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #3
	bhi _0824980C
	cmp r7, #0
	bne _0824973E
_0824980C:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start sub_08249818
sub_08249818: @ 0x08249818
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r3, #0
	movs r2, #0
	ldr r1, _08249864 @ =0x03005800
	ldr r0, [r1]
	ldrh r0, [r0, #0x14]
	cmp r0, r4
	beq _08249844
	adds r5, r1, #0
_0824982E:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bhi _08249844
	ldr r0, [r5]
	lsls r1, r2, #5
	adds r0, r0, r1
	ldrh r0, [r0, #0x14]
	cmp r0, r4
	bne _0824982E
_08249844:
	cmp r2, #4
	bne _0824984C
	movs r3, #0x80
	lsls r3, r3, #1
_0824984C:
	cmp r3, #0
	bne _08249870
	ldr r0, _08249868 @ =0x03005804
	ldr r0, [r0]
	strh r4, [r0, #0x1e]
	ldr r0, _0824986C @ =FUN_08248f58
	bl FUN_08247a78
	adds r0, r4, #0
	bl FUN_08247d0c
	b _08249878
	.align 2, 0
_08249864: .4byte 0x03005800
_08249868: .4byte 0x03005804
_0824986C: .4byte FUN_08248f58
_08249870:
	movs r0, #0x1f
	adds r1, r3, #0
	bl FUN_08248f58
_08249878:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sub_08249880
sub_08249880: @ 0x08249880
	push {lr}
	ldr r0, _08249890 @ =FUN_08249894
	bl FUN_08247a78
	bl FUN_08247d3c
	pop {r0}
	bx r0
	.align 2, 0
_08249890: .4byte FUN_08249894

	thumb_func_start FUN_08249894
FUN_08249894: @ 0x08249894
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x2c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0x24]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	str r1, [sp, #0x28]
	cmp r1, #0
	bne _08249996
	ldr r0, _08249950 @ =0x03005808
	ldr r0, [r0]
	adds r0, #0xdc
	ldr r0, [r0]
	ldrh r5, [r0, #4]
	ldrb r1, [r0, #6]
	mov sl, r1
	ldrb r0, [r0, #7]
	cmp r0, #0
	bne _08249996
	movs r0, #0x80
	lsls r0, r0, #0x11
	lsls r0, r1
	lsrs r2, r0, #0x18
	ldr r4, _08249954 @ =0x03005800
	ldr r3, [r4]
	ldrb r1, [r3, #2]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _08249996
	adds r0, r2, #0
	orrs r0, r1
	strb r0, [r3, #2]
	ldr r1, [r4]
	ldrb r0, [r1, #3]
	bics r0, r2
	strb r0, [r1, #3]
	ldr r1, [r4]
	adds r0, r1, #0
	adds r0, #0x94
	movs r2, #0
	strh r5, [r0]
	ldrb r0, [r1, #1]
	adds r0, #1
	strb r0, [r1, #1]
	ldr r0, [r4]
	strb r2, [r0]
	ldr r3, _08249958 @ =0x03005804
	ldr r2, [r3]
	ldrb r1, [r2]
	movs r0, #0x80
	orrs r0, r1
	strb r0, [r2]
	movs r5, #0
	adds r7, r4, #0
	add r6, sp, #0x20
	movs r0, #0
	mov r8, r0
_08249912:
	ldr r2, [r7]
	lsls r4, r5, #5
	adds r0, r2, r4
	ldr r1, [r3]
	ldrh r0, [r0, #0x14]
	ldrh r1, [r1, #0x1e]
	cmp r0, r1
	bne _0824996A
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _08249960
	mov sb, sp
	adds r0, r4, #0
	adds r0, #0x14
	adds r0, r2, r0
	mov r1, sp
	movs r2, #0x10
	bl CpuSet
	mov r1, r8
	strh r1, [r6]
	ldr r1, [r7]
	adds r1, #0x14
	adds r0, r6, #0
	ldr r2, _0824995C @ =0x01000040
	bl CpuSet
	ldr r0, [r7]
	mov r1, r8
	strb r1, [r0, #8]
	b _08249974
	.align 2, 0
_08249950: .4byte 0x03005808
_08249954: .4byte 0x03005800
_08249958: .4byte 0x03005804
_0824995C: .4byte 0x01000040
_08249960:
	adds r0, r4, #0
	adds r0, #0x14
	adds r2, r2, r0
	mov sb, r2
	b _08249974
_0824996A:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bls _08249912
_08249974:
	cmp r5, #3
	bhi _08249996
	ldr r4, _082499B0 @ =0x03005800
	mov r0, sl
	lsls r5, r0, #5
	adds r0, r5, #0
	adds r0, #0x14
	ldr r1, [r4]
	adds r1, r1, r0
	mov r0, sb
	movs r2, #0x10
	bl CpuSet
	ldr r0, [r4]
	adds r0, r0, r5
	mov r1, sl
	strb r1, [r0, #0x16]
_08249996:
	ldr r0, [sp, #0x24]
	ldr r1, [sp, #0x28]
	bl FUN_08248f58
	add sp, #0x2c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_082499B0: .4byte 0x03005800

	thumb_func_start FUN_082499b4
FUN_082499b4: @ 0x082499B4
	push {lr}
	adds r3, r0, #0
	movs r0, #0xff
	strb r0, [r3]
	ldr r0, _082499D4 @ =0x03005808
	ldr r0, [r0]
	adds r0, #0xdc
	ldr r2, [r0]
	ldrb r0, [r2]
	adds r0, #0x60
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _082499D8
	movs r0, #0x10
	b _082499E4
	.align 2, 0
_082499D4: .4byte 0x03005808
_082499D8:
	adds r2, #6
	ldrb r0, [r2]
	strb r0, [r1]
	ldrb r0, [r2, #1]
	strb r0, [r3]
	movs r0, #0
_082499E4:
	pop {r1}
	bx r1

	thumb_func_start FUN_082499e8
FUN_082499e8: @ 0x082499E8
	push {lr}
	ldr r0, _08249A14 @ =FUN_08249894
	bl FUN_08247a78
	bl FUN_08247d60
	ldr r0, _08249A18 @ =0x03005808
	ldr r0, [r0]
	adds r0, #0xdc
	ldr r1, [r0]
	ldrb r0, [r1, #6]
	cmp r0, #3
	bhi _08249A10
	ldr r0, _08249A1C @ =0x03005804
	ldr r0, [r0]
	adds r0, #0xa
	ldrb r1, [r1, #6]
	adds r0, r0, r1
	movs r1, #0
	strb r1, [r0]
_08249A10:
	pop {r0}
	bx r0
	.align 2, 0
_08249A14: .4byte FUN_08249894
_08249A18: .4byte 0x03005808
_08249A1C: .4byte 0x03005804

	thumb_func_start FUN_08249a20
FUN_08249a20: @ 0x08249A20
	push {r4, r5, lr}
	bl FUN_0824baf8
	ldr r0, _08249A68 @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _08249AF8
	ldr r4, _08249A6C @ =0x03005804
	ldr r1, [r4]
	ldrb r0, [r1, #6]
	cmp r0, #0
	beq _08249A3E
	subs r0, #1
	strb r0, [r1, #6]
_08249A3E:
	bl FUN_0824a290
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldr r2, [r4]
	ldrb r1, [r2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08249A70
	cmp r3, #0
	bne _08249A7E
	movs r0, #4
	orrs r0, r1
	strb r0, [r2]
	ldr r1, [r4]
	movs r0, #0xb4
	lsls r0, r0, #1
	strh r0, [r1, #0x20]
	b _08249A7A
	.align 2, 0
_08249A68: .4byte 0x03005800
_08249A6C: .4byte 0x03005804
_08249A70:
	cmp r3, #0
	beq _08249A90
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r2]
_08249A7A:
	cmp r3, #0
	beq _08249A90
_08249A7E:
	ldr r3, _08249A8C @ =0x03005804
	ldr r2, [r3]
	ldrb r1, [r2]
	movs r0, #0xfd
	ands r0, r1
	b _08249A9A
	.align 2, 0
_08249A8C: .4byte 0x03005804
_08249A90:
	ldr r3, _08249AEC @ =0x03005804
	ldr r2, [r3]
	ldrb r1, [r2]
	movs r0, #2
	orrs r0, r1
_08249A9A:
	strb r0, [r2]
	ldr r3, [r3]
	ldrb r1, [r3]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08249AF8
	ldrh r0, [r3, #0x20]
	cmp r0, #0
	bne _08249AF4
	movs r0, #0xfb
	ands r0, r1
	strb r0, [r3]
	ldr r0, _08249AF0 @ =0x03005800
	ldr r0, [r0]
	ldrb r1, [r0, #2]
	ldrb r0, [r0, #3]
	adds r5, r0, #0
	orrs r5, r1
	movs r4, #0
_08249AC2:
	adds r0, r5, #0
	asrs r0, r4
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08249AD4
	adds r0, r4, #0
	bl FUN_08249ebc
_08249AD4:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _08249AC2
	ldr r0, _08249AF0 @ =0x03005800
	ldr r1, [r0]
	movs r0, #0xff
	strb r0, [r1]
	movs r0, #1
	b _08249AFA
	.align 2, 0
_08249AEC: .4byte 0x03005804
_08249AF0: .4byte 0x03005800
_08249AF4:
	subs r0, #1
	strh r0, [r3, #0x20]
_08249AF8:
	movs r0, #0
_08249AFA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08249b00
FUN_08249b00: @ 0x08249B00
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	mov r8, r1
	str r2, [sp]
	str r3, [sp, #4]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r0, #0
	str r0, [sp, #8]
	movs r1, #0
	str r1, [sp, #0xc]
	mov r2, r8
	strb r1, [r2]
	mov r0, sp
	ldrb r1, [r0, #0xc]
	ldr r0, [sp]
	strb r1, [r0]
	mov r2, sp
	ldrb r0, [r2, #0xc]
	ldr r2, [sp, #4]
	strb r0, [r2]
	ldr r4, _08249BA0 @ =0x03005800
	ldr r0, [r4]
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08249B3E
	b _08249E9E
_08249B3E:
	ldr r0, _08249BA4 @ =0x030057D0
	ldr r0, [r0]
	ldrb r0, [r0, #0x14]
	cmp r0, #0
	bne _08249B4A
	b _08249E9E
_08249B4A:
	ldr r3, _08249BA8 @ =0x03005804
	ldr r2, [r3]
	ldrb r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08249B5E
	movs r0, #0xb4
	lsls r0, r0, #1
	strh r0, [r2, #0x20]
_08249B5E:
	ldr r1, [r3]
	ldrb r0, [r1, #6]
	cmp r0, #0
	bne _08249B70
	ldr r0, [r4]
	ldrb r0, [r0, #9]
	strb r0, [r1, #6]
	movs r1, #1
	str r1, [sp, #8]
_08249B70:
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x29
	bne _08249BB0
	ldr r0, _08249BAC @ =0x03005808
	ldr r0, [r0]
	adds r0, #0xdc
	ldr r1, [r0]
	ldrb r0, [r1, #4]
	mov r2, r8
	strb r0, [r2]
	ldrb r0, [r1, #5]
	ldr r1, [sp]
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bne _08249B9A
	ldr r0, [r4]
	ldrb r0, [r0, #2]
	strb r0, [r2]
_08249B9A:
	movs r2, #2
	str r2, [sp, #8]
	b _08249C08
	.align 2, 0
_08249BA0: .4byte 0x03005800
_08249BA4: .4byte 0x030057D0
_08249BA8: .4byte 0x03005804
_08249BAC: .4byte 0x03005808
_08249BB0:
	movs r0, #0x9b
	lsls r0, r0, #1
	cmp r5, r0
	bne _08249C00
	ldr r0, _08249C5C @ =0x03005808
	ldr r0, [r0]
	adds r0, #0xdc
	ldr r0, [r0]
	ldrb r6, [r0, #5]
	ldr r0, [r4]
	ldrb r0, [r0, #2]
	eors r6, r0
	ands r6, r0
	mov r0, r8
	strb r6, [r0]
	movs r0, #1
	ldr r1, [sp]
	strb r0, [r1]
	movs r5, #0
_08249BD6:
	mov r2, r8
	ldrb r0, [r2]
	asrs r0, r5
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08249BF6
	ldr r0, _08249C60 @ =0x03005800
	ldr r0, [r0]
	adds r0, #0xa
	adds r0, r0, r5
	movs r1, #0
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_08249ebc
_08249BF6:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bls _08249BD6
_08249C00:
	ldr r0, [sp, #8]
	cmp r0, #0
	bne _08249C08
	b _08249E9E
_08249C08:
	ldr r4, _08249C5C @ =0x03005808
	ldr r0, [r4]
	adds r0, #0xdc
	ldr r0, [r0]
	ldr r1, [r0]
	str r1, [sp, #0x10]
	ldr r0, [r0, #4]
	str r0, [sp, #0x14]
	ldr r0, _08249C64 @ =0x08248F99
	bl FUN_08247a78
	bl FUN_08247ae8
	bl FUN_08247a9c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #0xc]
	cmp r0, #0
	bne _08249C68
	ldr r0, [r4]
	adds r0, #0xdc
	ldr r0, [r0]
	adds r2, r0, #4
	movs r5, #0
	ldr r3, _08249C60 @ =0x03005800
_08249C3C:
	ldr r0, [r3]
	adds r0, #0xa
	adds r0, r0, r5
	ldrb r1, [r2]
	strb r1, [r0]
	adds r2, #1
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bls _08249C3C
	movs r2, #0
	mov sb, r2
	movs r5, #0
	b _08249C74
	.align 2, 0
_08249C5C: .4byte 0x03005808
_08249C60: .4byte 0x03005800
_08249C64: .4byte 0x08248F99
_08249C68:
	movs r0, #0x11
	ldr r1, [sp, #0xc]
	bl FUN_08248f58
	ldr r0, [sp, #0xc]
	b _08249EA0
_08249C74:
	movs r0, #0x80
	lsls r0, r0, #0x11
	lsls r0, r5
	lsrs r6, r0, #0x18
	adds r0, r5, #1
	mov sl, r0
	ldr r1, [sp, #0xc]
	cmp r1, #0
	beq _08249C88
	b _08249E52
_08249C88:
	ldr r2, [sp, #8]
	cmp r2, #1
	bne _08249D5E
	ldr r4, _08249CC8 @ =0x03005800
	ldr r1, [r4]
	ldrb r0, [r1, #2]
	ands r0, r6
	cmp r0, #0
	beq _08249D5E
	adds r0, r1, #0
	adds r0, #0xa
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #0
	bne _08249D50
	ldrb r0, [r1]
	cmp r0, #1
	bne _08249CD0
	ldr r2, _08249CCC @ =0x03005804
	ldr r1, [r2]
	adds r1, #0xa
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldr r0, [r2]
	adds r0, #0xa
	adds r0, r0, r5
	ldrb r0, [r0]
	cmp r0, #3
	bls _08249D5E
	b _08249D36
	.align 2, 0
_08249CC8: .4byte 0x03005800
_08249CCC: .4byte 0x03005804
_08249CD0:
	bl FUN_08247b30
	bl FUN_08247a9c
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08249D5E
	ldr r0, _08249D00 @ =0x03005808
	ldr r0, [r0]
	adds r0, #0xdc
	ldr r0, [r0]
	ldrb r0, [r0, #7]
	cmp r0, #0
	bne _08249D04
	mov r2, r8
	ldrb r1, [r2]
	adds r0, r6, #0
	orrs r0, r1
	strb r0, [r2]
	mov r0, sp
	ldrb r1, [r0, #8]
	ldr r0, [sp]
	b _08249D5C
	.align 2, 0
_08249D00: .4byte 0x03005808
_08249D04:
	ldr r2, _08249D4C @ =0x03005804
	ldr r1, [r2]
	adds r1, #0xa
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	ldr r2, [r2]
	lsrs r0, r0, #0x18
	ldrh r1, [r2, #0x1a]
	cmp r0, r1
	bls _08249D5E
	adds r0, r2, #0
	adds r0, #0xa
	adds r0, r0, r5
	mov r2, sp
	ldrb r2, [r2, #0xc]
	strb r2, [r0]
	ldr r0, [r4]
	ldrb r0, [r0, #2]
	bl FUN_08247f10
	bl FUN_08247a9c
_08249D36:
	mov r0, r8
	ldrb r1, [r0]
	adds r0, r6, #0
	orrs r0, r1
	mov r1, r8
	strb r0, [r1]
	mov r2, sp
	ldrb r0, [r2, #8]
	ldr r2, [sp]
	strb r0, [r2]
	b _08249D5E
	.align 2, 0
_08249D4C: .4byte 0x03005804
_08249D50:
	ldr r0, _08249DC0 @ =0x03005804
	ldr r0, [r0]
	adds r0, #0xa
	adds r0, r0, r5
	mov r1, sp
	ldrb r1, [r1, #0xc]
_08249D5C:
	strb r1, [r0]
_08249D5E:
	ldr r2, _08249DC4 @ =0x03005800
	mov ip, r2
	ldr r1, [r2]
	ldrb r7, [r1]
	adds r0, r5, #1
	mov sl, r0
	cmp r7, #1
	bne _08249E52
	adds r0, r1, #0
	adds r0, #0xa
	adds r4, r0, r5
	ldrb r3, [r4]
	cmp r3, #0
	beq _08249E52
	ldrb r2, [r1, #3]
	adds r0, r6, #0
	ands r0, r2
	cmp r0, #0
	beq _08249DCE
	cmp r3, #0xa
	bls _08249DC8
	ldr r2, [sp, #4]
	ldrb r1, [r2]
	adds r0, r6, #0
	orrs r0, r1
	strb r0, [r2]
	mov r0, ip
	ldr r2, [r0]
	ldrb r1, [r2, #2]
	adds r0, r6, #0
	orrs r0, r1
	movs r3, #0
	strb r0, [r2, #2]
	mov r2, ip
	ldr r1, [r2]
	ldrb r0, [r1, #3]
	bics r0, r6
	strb r0, [r1, #3]
	ldr r1, [r2]
	ldrb r0, [r1, #1]
	adds r0, #1
	strb r0, [r1, #1]
	ldr r0, _08249DC0 @ =0x03005804
	ldr r0, [r0]
	adds r0, #0xa
	adds r0, r0, r5
	strb r3, [r0]
	b _08249E52
	.align 2, 0
_08249DC0: .4byte 0x03005804
_08249DC4: .4byte 0x03005800
_08249DC8:
	movs r0, #0
	strb r0, [r4]
	b _08249E52
_08249DCE:
	ldrb r0, [r1, #2]
	orrs r0, r2
	ands r0, r6
	cmp r0, #0
	bne _08249E52
	bl FUN_08247b54
	bl FUN_08247a9c
	ldr r0, _08249E18 @ =0x03005808
	ldr r0, [r0]
	adds r0, #0xdc
	ldr r2, [r0]
	ldrb r0, [r2, #1]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r2, #8
	cmp r3, #0
	beq _08249E52
	ldrh r4, [r2]
	ldrb r0, [r2, #2]
	cmp r0, r5
	bne _08249E20
	ldr r0, _08249E1C @ =0x03005804
	ldr r0, [r0]
	lsls r1, r5, #1
	adds r0, #0x12
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	bne _08249E20
	lsls r7, r5
	mov r0, sb
	orrs r0, r7
	lsls r0, r0, #0x18
	b _08249E4E
	.align 2, 0
_08249E18: .4byte 0x03005808
_08249E1C: .4byte 0x03005804
_08249E20:
	adds r2, #4
	subs r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	beq _08249E52
	ldrh r4, [r2]
	ldrb r0, [r2, #2]
	cmp r0, r5
	bne _08249E20
	ldr r0, _08249EB0 @ =0x03005804
	ldr r0, [r0]
	lsls r1, r5, #1
	adds r0, #0x12
	adds r0, r0, r1
	ldrh r0, [r0]
	cmp r4, r0
	bne _08249E20
	movs r0, #1
	lsls r0, r5
	mov r1, sb
	orrs r1, r0
	lsls r0, r1, #0x18
_08249E4E:
	lsrs r0, r0, #0x18
	mov sb, r0
_08249E52:
	ldr r0, _08249EB4 @ =0x03005800
	ldr r0, [r0]
	ldrb r1, [r0, #2]
	mov r2, r8
	ldrb r0, [r2]
	ands r0, r1
	ands r6, r0
	cmp r6, #0
	beq _08249E6C
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08249ebc
_08249E6C:
	mov r1, sl
	lsls r0, r1, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bhi _08249E78
	b _08249C74
_08249E78:
	mov r2, sb
	cmp r2, #0
	beq _08249E88
	mov r0, sb
	bl FUN_08247f10
	bl FUN_08247a9c
_08249E88:
	ldr r1, _08249EB8 @ =0x03005808
	ldr r0, [r1]
	adds r0, #0xdc
	ldr r0, [r0]
	ldr r2, [sp, #0x10]
	str r2, [r0]
	ldr r0, [r1]
	adds r0, #0xdc
	ldr r0, [r0]
	ldr r1, [sp, #0x14]
	str r1, [r0, #4]
_08249E9E:
	movs r0, #0
_08249EA0:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08249EB0: .4byte 0x03005804
_08249EB4: .4byte 0x03005800
_08249EB8: .4byte 0x03005808

	thumb_func_start FUN_08249ebc
FUN_08249ebc: @ 0x08249EBC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov ip, r1
	movs r0, #0x80
	lsls r0, r0, #0x11
	lsls r0, r7
	lsrs r5, r0, #0x18
	ldr r1, _08249F60 @ =0x03005800
	ldr r4, [r1]
	ldrb r0, [r4, #2]
	ands r0, r5
	mov r8, r1
	cmp r0, #0
	beq _08249EEE
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _08249EEE
	subs r0, #1
	strb r0, [r4, #1]
_08249EEE:
	mov r3, r8
	ldr r2, [r3]
	mvns r6, r5
	ldrb r1, [r2, #2]
	adds r0, r6, #0
	ands r0, r1
	strb r0, [r2, #2]
	ldr r2, [r3]
	ldrb r1, [r2, #3]
	adds r0, r5, #0
	orrs r0, r1
	strb r0, [r2, #3]
	ldr r3, [r3]
	ldr r0, [r3]
	ldr r1, _08249F64 @ =0x00FF00FF
	ands r0, r1
	cmp r0, #0
	bne _08249F16
	movs r0, #0xff
	strb r0, [r3]
_08249F16:
	mov r0, ip
	cmp r0, #0
	beq _08249F54
	mov r1, sp
	movs r4, #0
	movs r0, #0
	strh r0, [r1]
	lsls r0, r7, #5
	adds r0, #0x14
	mov r2, r8
	ldr r1, [r2]
	adds r1, r1, r0
	ldr r2, _08249F68 @ =0x01000010
	mov r0, sp
	bl CpuSet
	mov r0, r8
	ldr r2, [r0]
	ldrb r1, [r2, #3]
	adds r0, r6, #0
	ands r0, r1
	strb r0, [r2, #3]
	mov r2, r8
	ldr r1, [r2]
	ldrb r0, [r1, #7]
	ands r6, r0
	strb r6, [r1, #7]
	ldr r0, [r2]
	adds r0, #0xa
	adds r0, r0, r7
	strb r4, [r0]
_08249F54:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08249F60: .4byte 0x03005800
_08249F64: .4byte 0x00FF00FF
_08249F68: .4byte 0x01000010

	thumb_func_start FUN_08249f6c
FUN_08249f6c: @ 0x08249F6C
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r2, _08249FB0 @ =0x03005800
	ldr r1, [r2]
	ldrb r0, [r1, #2]
	ldrb r1, [r1, #3]
	orrs r0, r1
	ands r0, r4
	cmp r0, #0
	beq _08249FF0
	ldr r0, _08249FB4 @ =0x03005804
	ldr r1, [r0]
	strb r4, [r1, #5]
	ldr r2, [r2]
	ldrb r1, [r2]
	adds r3, r0, #0
	cmp r1, #0xff
	bne _08249FB8
	ldr r0, [r3]
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08249FB8
	ldrb r0, [r2, #3]
	ands r0, r4
	cmp r0, #0
	beq _08249FF0
	movs r0, #0x30
	movs r1, #0
	bl FUN_08249ffc
	b _08249FF0
	.align 2, 0
_08249FB0: .4byte 0x03005800
_08249FB4: .4byte 0x03005804
_08249FB8:
	ldr r0, [r3]
	ldrb r0, [r0, #9]
	cmp r0, #0
	beq _08249FE4
	ldr r0, _08249FE0 @ =0x08248F99
	bl FUN_08247a78
	bl FUN_08247c7c
	bl FUN_08247a9c
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	beq _08249FE4
	movs r0, #0x1b
	bl FUN_08248f58
	b _08249FF0
	.align 2, 0
_08249FE0: .4byte 0x08248F99
_08249FE4:
	ldr r0, _08249FF8 @ =FUN_08249ffc
	bl FUN_08247a78
	adds r0, r4, #0
	bl FUN_08247f10
_08249FF0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08249FF8: .4byte FUN_08249ffc

	thumb_func_start FUN_08249ffc
FUN_08249ffc: @ 0x08249FFC
	push {r4, r5, r6, lr}
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	cmp r5, #3
	bne _0824A038
	ldr r0, _0824A0CC @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #0
	bne _0824A038
	ldr r0, _0824A0D0 @ =0x08248F99
	bl FUN_08247a78
	bl FUN_08247b30
	bl FUN_08247a9c
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0824A038
	ldr r0, _0824A0D4 @ =0x03005808
	ldr r0, [r0]
	adds r0, #0xdc
	ldr r0, [r0]
	ldrb r0, [r0, #7]
	cmp r0, #0
	bne _0824A038
	movs r5, #0
_0824A038:
	ldr r3, _0824A0D8 @ =0x03005804
	ldr r2, [r3]
	ldr r0, _0824A0CC @ =0x03005800
	ldr r1, [r0]
	ldrb r0, [r1, #2]
	ldrb r1, [r1, #3]
	orrs r0, r1
	ldrb r1, [r2, #5]
	ands r0, r1
	strb r0, [r2, #5]
	ldr r0, _0824A0D4 @ =0x03005808
	ldr r0, [r0]
	adds r0, #0xdc
	ldr r1, [r0]
	ldr r0, [r3]
	ldrb r0, [r0, #5]
	strb r0, [r1, #8]
	cmp r5, #0
	bne _0824A086
	movs r4, #0
_0824A060:
	movs r0, #0x80
	lsls r0, r0, #0x11
	lsls r0, r4
	lsrs r0, r0, #0x18
	ldr r1, _0824A0D8 @ =0x03005804
	ldr r1, [r1]
	ldrb r1, [r1, #5]
	ands r0, r1
	cmp r0, #0
	beq _0824A07C
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08249ebc
_0824A07C:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _0824A060
_0824A086:
	ldr r0, _0824A0CC @ =0x03005800
	ldr r2, [r0]
	ldrb r1, [r2, #2]
	ldrb r0, [r2, #3]
	orrs r0, r1
	cmp r0, #0
	bne _0824A098
	movs r0, #0xff
	strb r0, [r2]
_0824A098:
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_08248f58
	ldr r0, _0824A0D8 @ =0x03005804
	ldr r0, [r0]
	ldrb r0, [r0, #9]
	cmp r0, #0
	beq _0824A0C6
	ldr r0, _0824A0D0 @ =0x08248F99
	bl FUN_08247a78
	bl FUN_08247c34
	bl FUN_08247a9c
	adds r5, r0, #0
	cmp r5, #0
	beq _0824A0C6
	movs r0, #0x19
	adds r1, r5, #0
	bl FUN_08248f58
_0824A0C6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0824A0CC: .4byte 0x03005800
_0824A0D0: .4byte 0x08248F99
_0824A0D4: .4byte 0x03005808
_0824A0D8: .4byte 0x03005804

	thumb_func_start sub_0824A0DC
sub_0824A0DC: @ 0x0824A0DC
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _0824A12C @ =0x03005804
	ldr r0, [r0]
	strb r5, [r0, #5]
	movs r4, #0
	movs r0, #1
	ands r0, r5
	ldr r2, _0824A130 @ =FUN_08248f58
	cmp r0, #0
	bne _0824A10A
	movs r1, #1
_0824A0F6:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bhi _0824A10A
	adds r0, r5, #0
	asrs r0, r4
	ands r0, r1
	cmp r0, #0
	beq _0824A0F6
_0824A10A:
	adds r0, r2, #0
	bl FUN_08247a78
	ldr r0, _0824A134 @ =0x03005800
	ldr r1, [r0]
	lsls r0, r4, #5
	adds r0, r1, r0
	ldrh r0, [r0, #0x14]
	adds r1, #0x94
	ldrh r1, [r1]
	adds r2, r5, #0
	bl FUN_08247f78
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0824A12C: .4byte 0x03005804
_0824A130: .4byte FUN_08248f58
_0824A134: .4byte 0x03005800

	thumb_func_start FUN_0824a138
FUN_0824a138: @ 0x0824A138
	push {lr}
	ldr r0, _0824A148 @ =FUN_0824a14c
	bl FUN_08247a78
	bl FUN_08247fb4
	pop {r0}
	bx r0
	.align 2, 0
_0824A148: .4byte FUN_0824a14c

	thumb_func_start FUN_0824a14c
FUN_0824a14c: @ 0x0824A14C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	cmp r7, #0
	bne _0824A1D0
	ldr r0, _0824A1E4 @ =0x03005808
	ldr r0, [r0]
	adds r0, #0xdc
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	cmp r0, #0
	bne _0824A1D0
	ldr r0, _0824A1E8 @ =0x03005804
	ldr r1, [r0]
	ldrb r1, [r1, #5]
	adds r6, r0, #0
	cmp r1, #0
	beq _0824A1D0
	ldr r1, _0824A1EC @ =0x03005800
	ldr r0, [r1]
	strb r7, [r0]
	movs r4, #0
	adds r5, r1, #0
	mov ip, r4
_0824A186:
	movs r0, #0x80
	lsls r0, r0, #0x11
	lsls r0, r4
	lsrs r3, r0, #0x18
	ldr r2, [r5]
	ldr r0, [r6]
	ldrb r0, [r0, #5]
	ands r0, r3
	ldrb r1, [r2, #3]
	ands r0, r1
	cmp r0, #0
	beq _0824A1C0
	ldrb r1, [r2, #2]
	adds r0, r3, #0
	orrs r0, r1
	strb r0, [r2, #2]
	ldr r1, [r5]
	ldrb r0, [r1, #3]
	bics r0, r3
	strb r0, [r1, #3]
	ldr r1, [r5]
	ldrb r0, [r1, #1]
	adds r0, #1
	strb r0, [r1, #1]
	ldr r0, [r6]
	adds r0, #0xa
	adds r0, r0, r4
	mov r1, ip
	strb r1, [r0]
_0824A1C0:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _0824A186
	ldr r1, [r6]
	movs r0, #0
	strb r0, [r1, #5]
_0824A1D0:
	mov r0, r8
	adds r1, r7, #0
	bl FUN_08248f58
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0824A1E4: .4byte 0x03005808
_0824A1E8: .4byte 0x03005804
_0824A1EC: .4byte 0x03005800

	thumb_func_start FUN_0824a1f0
FUN_0824a1f0: @ 0x0824A1F0
	push {lr}
	adds r2, r0, #0
	movs r0, #0xff
	strb r0, [r2]
	ldr r0, _0824A210 @ =0x03005808
	ldr r0, [r0]
	adds r0, #0xdc
	ldr r1, [r0]
	ldrb r0, [r1]
	adds r0, #0x4d
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _0824A214
	movs r0, #0x10
	b _0824A21A
	.align 2, 0
_0824A210: .4byte 0x03005808
_0824A214:
	ldrb r0, [r1, #4]
	strb r0, [r2]
	movs r0, #0
_0824A21A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start sub_0824A220
sub_0824A220: @ 0x0824A220
	push {lr}
	ldr r0, _0824A230 @ =FUN_0824a14c
	bl FUN_08247a78
	bl FUN_08247fd8
	pop {r0}
	bx r0
	.align 2, 0
_0824A230: .4byte FUN_0824a14c
_0824A234:
	.byte 0x70, 0xB5, 0x05, 0x1C, 0x0E, 0x1C, 0x2B, 0x68, 0x31, 0x68, 0x01, 0x3A
	.byte 0x01, 0x20, 0x40, 0x42, 0x82, 0x42, 0x07, 0xD0, 0x04, 0x1C, 0x18, 0x78, 0x08, 0x70, 0x01, 0x33
	.byte 0x01, 0x31, 0x01, 0x3A, 0xA2, 0x42, 0xF8, 0xD1, 0x2B, 0x60, 0x31, 0x60, 0x70, 0xBC, 0x01, 0xBC
	.byte 0x00, 0x47, 0x00, 0x00

	thumb_func_start FUN_0824a264
FUN_0824a264: @ 0x0824A264
	push {lr}
	movs r0, #1
	bl FUN_08247a00
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #1
	bne _0824A284
	ldr r0, _0824A280 @ =FUN_08248f58
	bl FUN_08247a78
	bl FUN_08247e38
	b _0824A28C
	.align 2, 0
_0824A280: .4byte FUN_08248f58
_0824A284:
	movs r0, #0x27
	movs r1, #0
	bl FUN_08248f58
_0824A28C:
	pop {r0}
	bx r0

	thumb_func_start FUN_0824a290
FUN_0824a290: @ 0x0824A290
	push {lr}
	movs r0, #1
	bl FUN_08247a00
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #1
	bne _0824A2BE
	ldr r0, _0824A2C4 @ =0x030057D0
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x2c
	ldrb r0, [r0]
	cmp r0, #0
	beq _0824A2BE
	ldrb r0, [r1, #6]
	cmp r0, #0x27
	beq _0824A2BC
	cmp r0, #0x25
	beq _0824A2BC
	cmp r0, #0x37
	bne _0824A2BE
_0824A2BC:
	movs r2, #0
_0824A2BE:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0
_0824A2C4: .4byte 0x030057D0

	thumb_func_start FUN_0824a2c8
FUN_0824a2c8: @ 0x0824A2C8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r1, _0824A34C @ =0x04000208
	ldrh r0, [r1]
	mov r8, r0
	movs r0, #0
	strh r0, [r1]
	movs r5, #0
	mov r0, sp
	adds r0, #2
	movs r7, #0
	adds r6, r0, #0
_0824A2E4:
	mov r0, sp
	strh r7, [r0]
	ldr r0, _0824A350 @ =0x030057F0
	lsls r4, r5, #2
	adds r0, r4, r0
	ldr r1, [r0]
	mov r0, sp
	ldr r2, _0824A354 @ =0x01000034
	bl CpuSet
	strh r7, [r6]
	ldr r0, _0824A358 @ =0x030057E0
	adds r4, r4, r0
	ldr r1, [r4]
	adds r0, r6, #0
	ldr r2, _0824A35C @ =0x0100000A
	bl CpuSet
	ldr r3, _0824A360 @ =0x03005800
	ldr r0, [r3]
	adds r0, #0x10
	adds r0, r0, r5
	movs r1, #0x10
	strb r1, [r0]
	adds r0, r5, #1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #3
	bls _0824A2E4
	ldr r2, [r3]
	movs r1, #0
	movs r0, #0x57
	strb r0, [r2, #0xf]
	ldr r0, [r3]
	strb r1, [r0, #4]
	ldr r0, [r3]
	strb r1, [r0, #5]
	ldr r0, [r3]
	strb r1, [r0, #6]
	ldr r0, _0824A364 @ =0x03005804
	ldr r0, [r0]
	strb r1, [r0, #2]
	ldr r0, _0824A34C @ =0x04000208
	mov r1, r8
	strh r1, [r0]
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0824A34C: .4byte 0x04000208
_0824A350: .4byte 0x030057F0
_0824A354: .4byte 0x01000034
_0824A358: .4byte 0x030057E0
_0824A35C: .4byte 0x0100000A
_0824A360: .4byte 0x03005800
_0824A364: .4byte 0x03005804

	thumb_func_start FUN_0824a368
FUN_0824a368: @ 0x0824A368
	push {r4, r5, r6, lr}
	adds r4, r2, #0
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	adds r5, r2, #0
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	ldr r0, _0824A3A0 @ =0x03005804
	ldr r0, [r0]
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0824A3A8
	ldr r6, _0824A3A4 @ =0x03005800
	cmp r3, #0
	bne _0824A394
	ldr r1, [r6]
	ldrb r0, [r1, #0xf]
	ldrh r4, [r4, #0x2e]
	adds r0, r0, r4
	strb r0, [r1, #0xf]
_0824A394:
	ldr r1, [r6]
	ldrb r0, [r1, #0xf]
	adds r0, #3
	strb r0, [r1, #0xf]
	b _0824A3C8
	.align 2, 0
_0824A3A0: .4byte 0x03005804
_0824A3A4: .4byte 0x03005800
_0824A3A8:
	ldr r6, _0824A3D0 @ =0x03005800
	cmp r3, #0
	bne _0824A3BC
	ldr r1, [r6]
	adds r1, #0x10
	adds r1, r1, r2
	ldrb r0, [r1]
	ldrh r4, [r4, #0x2e]
	adds r0, r0, r4
	strb r0, [r1]
_0824A3BC:
	ldr r1, [r6]
	adds r1, #0x10
	adds r1, r1, r5
	ldrb r0, [r1]
	adds r0, #2
	strb r0, [r1]
_0824A3C8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0824A3D0: .4byte 0x03005800

	thumb_func_start FUN_0824a3d4
FUN_0824a3d4: @ 0x0824A3D4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	cmp r7, #3
	bls _0824A3F4
	movs r0, #0x80
	lsls r0, r0, #3
	b _0824A56C
_0824A3F4:
	movs r0, #0xf
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	bne _0824A404
	movs r0, #0xc0
	lsls r0, r0, #3
	b _0824A56C
_0824A404:
	ldr r1, _0824A448 @ =0x04000208
	ldrh r0, [r1]
	mov sl, r0
	movs r0, #0
	strh r0, [r1]
	movs r0, #0xc
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	beq _0824A4CC
	movs r3, #0
	ldr r1, _0824A44C @ =0x030057F0
	lsls r0, r7, #2
	adds r0, r0, r1
	mov sb, r0
_0824A422:
	movs r4, #0
	cmp r3, #0
	bne _0824A454
	movs r0, #4
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _0824A474
	mov r2, sb
	ldr r4, [r2]
	ldr r0, _0824A450 @ =0x03005800
	ldr r2, [r0]
	adds r0, r4, #0
	adds r0, #0x2c
	ldrb r1, [r0]
	ldrb r0, [r2, #4]
	bics r0, r1
	strb r0, [r2, #4]
	b _0824A474
	.align 2, 0
_0824A448: .4byte 0x04000208
_0824A44C: .4byte 0x030057F0
_0824A450: .4byte 0x03005800
_0824A454:
	movs r0, #8
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _0824A474
	mov r2, sb
	ldr r0, [r2]
	adds r4, r0, #0
	adds r4, #0x34
	ldr r0, _0824A508 @ =0x03005800
	ldr r2, [r0]
	movs r1, #1
	lsls r1, r7
	ldrb r0, [r2, #5]
	bics r0, r1
	strb r0, [r2, #5]
_0824A474:
	adds r6, r3, #1
	cmp r4, #0
	beq _0824A4C4
	ldrh r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #8
	adds r1, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0824A4B4
	lsls r1, r3, #0x18
	lsrs r1, r1, #0x18
	adds r0, r7, #0
	adds r2, r4, #0
	bl FUN_0824a368
	movs r1, #0
	adds r2, r4, #0
	adds r2, #0x2c
	movs r5, #1
	movs r3, #0
_0824A49E:
	ldrb r0, [r2]
	asrs r0, r1
	ands r0, r5
	cmp r0, #0
	beq _0824A4AA
	strh r3, [r4, #2]
_0824A4AA:
	adds r0, r1, #1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #3
	bls _0824A49E
_0824A4B4:
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _0824A50C @ =0x0100001A
	bl CpuSet
_0824A4C4:
	lsls r0, r6, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #1
	bls _0824A422
_0824A4CC:
	movs r0, #1
	mov r4, r8
	ands r0, r4
	cmp r0, #0
	beq _0824A542
	ldr r1, _0824A510 @ =0x030057E0
	lsls r0, r7, #2
	adds r0, r0, r1
	ldr r3, [r0]
	ldrh r1, [r3]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0824A534
	ldr r0, _0824A514 @ =0x03005804
	ldr r0, [r0]
	ldrb r1, [r0]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0824A518
	ldr r2, _0824A508 @ =0x03005800
	ldr r1, [r2]
	ldrb r0, [r1, #0xf]
	adds r0, #3
	ldrb r4, [r3, #4]
	adds r0, r0, r4
	strb r0, [r1, #0xf]
	b _0824A52A
	.align 2, 0
_0824A508: .4byte 0x03005800
_0824A50C: .4byte 0x0100001A
_0824A510: .4byte 0x030057E0
_0824A514: .4byte 0x03005804
_0824A518:
	ldr r2, _0824A57C @ =0x03005800
	ldr r1, [r2]
	adds r1, #0x10
	adds r1, r1, r7
	ldrb r0, [r1]
	adds r0, #2
	ldrb r4, [r3, #4]
	adds r0, r0, r4
	strb r0, [r1]
_0824A52A:
	ldr r2, [r2]
	ldrb r1, [r3, #3]
	ldrb r0, [r2, #6]
	bics r0, r1
	strb r0, [r2, #6]
_0824A534:
	mov r0, sp
	movs r1, #0
	strh r1, [r0]
	ldr r2, _0824A580 @ =0x01000006
	adds r1, r3, #0
	bl CpuSet
_0824A542:
	movs r0, #2
	mov r1, r8
	ands r0, r1
	cmp r0, #0
	beq _0824A564
	mov r1, sp
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0824A584 @ =0x030057E0
	lsls r0, r7, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r1, #0xc
	ldr r2, _0824A588 @ =0x01000004
	mov r0, sp
	bl CpuSet
_0824A564:
	ldr r0, _0824A58C @ =0x04000208
	mov r2, sl
	strh r2, [r0]
	movs r0, #0
_0824A56C:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0824A57C: .4byte 0x03005800
_0824A580: .4byte 0x01000006
_0824A584: .4byte 0x030057E0
_0824A588: .4byte 0x01000004
_0824A58C: .4byte 0x04000208

	thumb_func_start FUN_0824a590
FUN_0824a590: @ 0x0824A590
	push {r4, r5, r6, lr}
	adds r5, r2, #0
	adds r6, r3, #0
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r2, r3, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	adds r4, r1, #0
	cmp r1, #3
	bls _0824A5AC
	movs r0, #0x80
	lsls r0, r0, #3
	b _0824A5E4
_0824A5AC:
	movs r0, #0x20
	ands r0, r3
	cmp r0, #0
	beq _0824A5C8
	ldr r0, _0824A5C4 @ =0x030057F0
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	str r5, [r0, #0x68]
	str r6, [r0, #0x6c]
	b _0824A5E2
	.align 2, 0
_0824A5C4: .4byte 0x030057F0
_0824A5C8:
	movs r0, #0x10
	ands r2, r0
	cmp r2, #0
	bne _0824A5D6
	movs r0, #0xc0
	lsls r0, r0, #3
	b _0824A5E4
_0824A5D6:
	ldr r0, _0824A5EC @ =0x030057E0
	lsls r1, r4, #2
	adds r1, r1, r0
	ldr r0, [r1]
	str r5, [r0, #0x14]
	str r6, [r0, #0x18]
_0824A5E2:
	movs r0, #0
_0824A5E4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0824A5EC: .4byte 0x030057E0

	thumb_func_start FUN_0824a5f0
FUN_0824a5f0: @ 0x0824A5F0
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	str r3, [sp]
	movs r0, #0x20
	adds r1, r4, #0
	adds r2, r5, #0
	adds r3, r6, #0
	bl FUN_0824a68c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0824a61c
FUN_0824a61c: @ 0x0824A61C
	push {lr}
	sub sp, #4
	adds r3, r1, #0
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	ldr r0, _0824A638 @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #1
	bne _0824A63C
	adds r0, r2, #3
	b _0824A63E
	.align 2, 0
_0824A638: .4byte 0x03005800
_0824A63C:
	adds r0, r2, #2
_0824A63E:
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r0, #0
	str r0, [sp]
	movs r0, #0x10
	bl FUN_0824a68c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add sp, #4
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0824a658
FUN_0824a658: @ 0x0824A658
	push {lr}
	sub sp, #4
	adds r2, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r1, #0x80
	lsls r1, r1, #0x11
	lsls r1, r0
	lsrs r1, r1, #0x18
	ldr r0, _0824A688 @ =0x03005800
	ldr r3, [r0]
	adds r3, #0x98
	movs r0, #0x1a
	str r0, [sp]
	movs r0, #0x40
	bl FUN_0824a68c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add sp, #4
	pop {r1}
	bx r1
	.align 2, 0
_0824A688: .4byte 0x03005800

	thumb_func_start FUN_0824a68c
FUN_0824a68c: @ 0x0824A68C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r3, [sp]
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	ldr r0, _0824A6B8 @ =0x03005800
	ldr r2, [r0]
	ldrb r1, [r2]
	mov sl, r0
	cmp r1, #0xff
	bne _0824A6C0
	ldr r0, _0824A6BC @ =0x00000301
	b _0824A876
	.align 2, 0
_0824A6B8: .4byte 0x03005800
_0824A6BC: .4byte 0x00000301
_0824A6C0:
	movs r0, #0xf
	ands r0, r3
	cmp r0, #0
	bne _0824A6CE
	movs r0, #0x80
	lsls r0, r0, #3
	b _0824A876
_0824A6CE:
	ldrb r0, [r2, #2]
	ldrb r1, [r2, #3]
	orrs r0, r1
	ands r0, r3
	cmp r0, r3
	beq _0824A6E4
	ldr r0, _0824A6E0 @ =0x00000401
	b _0824A876
	.align 2, 0
_0824A6E0: .4byte 0x00000401
_0824A6E4:
	movs r0, #0x10
	ands r0, r6
	cmp r0, #0
	beq _0824A6F0
	ldrb r0, [r2, #6]
	b _0824A6F2
_0824A6F0:
	ldrb r0, [r2, #4]
_0824A6F2:
	ands r0, r3
	cmp r0, #0
	beq _0824A700
	ldr r0, _0824A6FC @ =0x00000402
	b _0824A876
	.align 2, 0
_0824A6FC: .4byte 0x00000402
_0824A700:
	movs r2, #0
	movs r0, #1
	ands r0, r3
	ldr r4, _0824A730 @ =0x085A8AE0
	cmp r0, #0
	bne _0824A722
	movs r1, #1
_0824A70E:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bhi _0824A722
	adds r0, r3, #0
	asrs r0, r2
	ands r0, r1
	cmp r0, #0
	beq _0824A70E
_0824A722:
	mov r0, sl
	ldr r1, [r0]
	ldrb r0, [r1]
	cmp r0, #1
	bne _0824A734
	adds r1, #0xf
	b _0824A73E
	.align 2, 0
_0824A730: .4byte 0x085A8AE0
_0824A734:
	cmp r0, #0
	bne _0824A740
	adds r0, r2, #0
	adds r0, #0x10
	adds r1, r1, r0
_0824A73E:
	mov sb, r1
_0824A740:
	mov r1, sl
	ldr r0, [r1]
	ldrb r0, [r0]
	lsls r0, r0, #4
	adds r0, r0, r4
	ldrb r4, [r0]
	mov r0, sb
	ldrb r0, [r0]
	cmp r8, r0
	bhi _0824A758
	cmp r8, r4
	bhi _0824A75E
_0824A758:
	movs r0, #0xa0
	lsls r0, r0, #3
	b _0824A876
_0824A75E:
	ldr r1, _0824A7AC @ =0x04000208
	ldrh r0, [r1]
	str r0, [sp, #4]
	movs r7, #0
	strh r7, [r1]
	movs r0, #0x20
	ands r0, r6
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0
	bne _0824A778
	cmp r6, #0x40
	bne _0824A834
_0824A778:
	ldr r1, _0824A7B0 @ =0x030057F0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r0, [r0]
	mov ip, r0
	movs r1, #0
	strh r1, [r0, #0x18]
	mov r1, ip
	adds r1, #0x2d
	mov r2, ip
	str r1, [r2, #4]
	movs r0, #7
	str r0, [r2, #0x14]
	mov r0, ip
	adds r0, #0x2c
	strb r3, [r0]
	strb r3, [r2, #0x1a]
	mov r2, r8
	subs r0, r2, r4
	mov r2, ip
	strh r0, [r2, #0x2e]
	cmp r5, #0
	beq _0824A7B4
	strb r7, [r1]
	b _0824A7B8
	.align 2, 0
_0824A7AC: .4byte 0x04000208
_0824A7B0: .4byte 0x030057F0
_0824A7B4:
	movs r0, #1
	strb r0, [r1]
_0824A7B8:
	ldr r0, [sp, #0x28]
	mov r1, ip
	str r0, [r1, #0x30]
	ldr r2, [sp]
	str r2, [r1, #0x28]
	movs r1, #0
	mov r0, ip
	strb r1, [r0, #0x1f]
	adds r0, #0x20
	strb r1, [r0]
	mov r4, ip
	adds r4, #0x1b
	movs r6, #0
	mov r2, ip
	adds r2, #0x21
	movs r5, #1
_0824A7D8:
	adds r0, r4, r1
	strb r6, [r0]
	adds r0, r2, r1
	strb r5, [r0]
	adds r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #3
	bls _0824A7D8
	movs r2, #0
	movs r5, #1
	ldr r4, _0824A82C @ =0x030057F0
	movs r1, #0
_0824A7F2:
	adds r0, r3, #0
	asrs r0, r2
	ands r0, r5
	cmp r0, #0
	beq _0824A804
	lsls r0, r2, #2
	adds r0, r0, r4
	ldr r0, [r0]
	strh r1, [r0, #2]
_0824A804:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _0824A7F2
	mov r1, sl
	ldr r2, [r1]
	ldrb r1, [r2, #4]
	adds r0, r3, #0
	orrs r0, r1
	strb r0, [r2, #4]
	mov r2, sb
	ldrb r0, [r2]
	mov r1, r8
	subs r0, r0, r1
	strb r0, [r2]
	ldr r0, _0824A830 @ =0x00008021
	mov r2, ip
	strh r0, [r2]
	b _0824A86C
	.align 2, 0
_0824A82C: .4byte 0x030057F0
_0824A830: .4byte 0x00008021
_0824A834:
	movs r0, #0x10
	ands r0, r6
	cmp r0, #0
	beq _0824A86C
	ldr r1, _0824A888 @ =0x030057E0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	strb r3, [r1, #3]
	ldr r0, [sp]
	str r0, [r1, #8]
	mov r2, r8
	subs r0, r2, r4
	strh r0, [r1, #4]
	mov r2, sb
	ldrb r0, [r2]
	mov r2, r8
	subs r0, r0, r2
	mov r2, sb
	strb r0, [r2]
	ldr r0, _0824A88C @ =0x00008024
	strh r0, [r1]
	mov r0, sl
	ldr r2, [r0]
	ldrb r1, [r2, #6]
	adds r0, r3, #0
	orrs r0, r1
	strb r0, [r2, #6]
_0824A86C:
	ldr r0, _0824A890 @ =0x04000208
	mov r1, sp
	ldrh r1, [r1, #4]
	strh r1, [r0]
	movs r0, #0
_0824A876:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0824A888: .4byte 0x030057E0
_0824A88C: .4byte 0x00008024
_0824A890: .4byte 0x04000208

	thumb_func_start FUN_0824a894
FUN_0824a894: @ 0x0824A894
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	lsls r1, r1, #0x18
	lsrs r7, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r6, r2, #0x18
	cmp r7, #3
	bls _0824A8B8
	movs r0, #0x80
	lsls r0, r0, #3
	b _0824A9EC
_0824A8B8:
	cmp r0, #0x20
	bne _0824A958
	ldr r0, _0824A948 @ =0x030057F0
	mov ip, r0
	lsls r0, r7, #2
	add r0, ip
	ldr r5, [r0]
	ldrh r2, [r5]
	ldr r1, _0824A94C @ =0x00008020
	adds r0, r1, #0
	ands r0, r2
	cmp r0, r1
	bne _0824A96E
	ldrb r0, [r5, #0x1a]
	adds r3, r6, #0
	eors r3, r0
	adds r2, r3, #0
	ands r2, r6
	cmp r2, #0
	bne _0824A9A6
	cmp r3, #0
	bne _0824A8E6
	b _0824A9EA
_0824A8E6:
	ldr r1, _0824A950 @ =0x04000208
	ldrh r0, [r1]
	mov r8, r0
	strh r2, [r1]
	movs r2, #0
	mvns r1, r3
	str r1, [sp]
	lsls r4, r6, #0x18
	mov sl, r4
	movs r0, #1
	mov sb, r0
	movs r1, #0
_0824A8FE:
	adds r0, r3, #0
	asrs r0, r2
	mov r4, sb
	ands r0, r4
	cmp r0, #0
	beq _0824A912
	lsls r0, r2, #2
	add r0, ip
	ldr r0, [r0]
	strh r1, [r0, #2]
_0824A912:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _0824A8FE
	ldr r0, _0824A954 @ =0x03005800
	ldr r1, [r0]
	ldrb r0, [r1, #4]
	ldr r2, [sp]
	ands r2, r0
	strb r2, [r1, #4]
	strb r6, [r5, #0x1a]
	mov r0, sl
	cmp r0, #0
	bne _0824A93E
	adds r0, r7, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_0824a368
	movs r0, #0x27
	strh r0, [r5]
_0824A93E:
	ldr r0, _0824A950 @ =0x04000208
	mov r1, r8
	strh r1, [r0]
	b _0824A9EA
	.align 2, 0
_0824A948: .4byte 0x030057F0
_0824A94C: .4byte 0x00008020
_0824A950: .4byte 0x04000208
_0824A954: .4byte 0x03005800
_0824A958:
	cmp r3, #0x10
	bne _0824A9E4
	ldr r3, _0824A974 @ =0x030057E0
	lsls r1, r7, #2
	adds r0, r1, r3
	ldr r0, [r0]
	ldrh r2, [r0]
	ldr r0, _0824A978 @ =0x00008024
	adds r5, r3, #0
	cmp r2, r0
	beq _0824A980
_0824A96E:
	ldr r0, _0824A97C @ =0x00000403
	b _0824A9EC
	.align 2, 0
_0824A974: .4byte 0x030057E0
_0824A978: .4byte 0x00008024
_0824A97C: .4byte 0x00000403
_0824A980:
	movs r3, #0
	movs r2, #0
	adds r4, r5, #0
_0824A986:
	cmp r2, r7
	beq _0824A994
	lsls r0, r2, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldrb r0, [r0, #3]
	orrs r3, r0
_0824A994:
	adds r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #3
	bls _0824A986
	adds r2, r6, #0
	ands r2, r3
	cmp r2, #0
	beq _0824A9B0
_0824A9A6:
	ldr r0, _0824A9AC @ =0x00000404
	b _0824A9EC
	.align 2, 0
_0824A9AC: .4byte 0x00000404
_0824A9B0:
	ldr r3, _0824A9DC @ =0x04000208
	ldrh r0, [r3]
	mov r8, r0
	strh r2, [r3]
	ldr r4, _0824A9E0 @ =0x03005800
	ldr r2, [r4]
	adds r5, r1, r5
	ldr r0, [r5]
	ldrb r1, [r0, #3]
	ldrb r0, [r2, #6]
	bics r0, r1
	strb r0, [r2, #6]
	ldr r2, [r4]
	ldrb r1, [r2, #6]
	adds r0, r6, #0
	orrs r0, r1
	strb r0, [r2, #6]
	ldr r0, [r5]
	strb r6, [r0, #3]
	mov r2, r8
	strh r2, [r3]
	b _0824A9EA
	.align 2, 0
_0824A9DC: .4byte 0x04000208
_0824A9E0: .4byte 0x03005800
_0824A9E4:
	movs r0, #0xc0
	lsls r0, r0, #3
	b _0824A9EC
_0824A9EA:
	movs r0, #0
_0824A9EC:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0824a9fc
FUN_0824a9fc: @ 0x0824A9FC
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #3
	bls _0824AA0C
	movs r0, #0x80
	lsls r0, r0, #3
	b _0824AA66
_0824AA0C:
	ldr r1, _0824AA38 @ =0x030057F0
	lsls r0, r3, #2
	adds r0, r0, r1
	ldr r2, [r0]
	adds r5, r2, #0
	adds r5, #0x34
	ldr r1, _0824AA3C @ =0x04000208
	ldrh r0, [r1]
	adds r4, r0, #0
	movs r0, #0
	strh r0, [r1]
	ldrh r1, [r2, #0x34]
	movs r0, #0x80
	lsls r0, r0, #8
	ands r0, r1
	cmp r0, #0
	beq _0824AA60
	ldr r0, _0824AA40 @ =0x00008043
	cmp r1, r0
	bne _0824AA44
	movs r0, #0x48
	b _0824AA46
	.align 2, 0
_0824AA38: .4byte 0x030057F0
_0824AA3C: .4byte 0x04000208
_0824AA40: .4byte 0x00008043
_0824AA44:
	movs r0, #0x47
_0824AA46:
	strh r0, [r2, #0x34]
	ldr r0, _0824AA6C @ =0x03005800
	ldr r2, [r0]
	movs r1, #1
	lsls r1, r3
	ldrb r0, [r2, #5]
	bics r0, r1
	strb r0, [r2, #5]
	adds r0, r3, #0
	movs r1, #1
	adds r2, r5, #0
	bl FUN_0824a368
_0824AA60:
	ldr r0, _0824AA70 @ =0x04000208
	strh r4, [r0]
	movs r0, #0
_0824AA66:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0824AA6C: .4byte 0x03005800
_0824AA70: .4byte 0x04000208

	thumb_func_start FUN_0824aa74
FUN_0824aa74: @ 0x0824AA74
	push {r4, r5, r6, r7, lr}
	adds r7, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r3, r0, #0
	lsls r2, r2, #0x18
	lsrs r5, r2, #0x18
	cmp r0, #3
	bls _0824AA8C
	movs r0, #0x80
	lsls r0, r0, #3
	b _0824AB00
_0824AA8C:
	ldr r1, _0824AAA0 @ =0x030057E0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	ldrh r1, [r4]
	ldr r0, _0824AAA4 @ =0x00008024
	cmp r1, r0
	beq _0824AAAC
	ldr r0, _0824AAA8 @ =0x00000403
	b _0824AB00
	.align 2, 0
_0824AAA0: .4byte 0x030057E0
_0824AAA4: .4byte 0x00008024
_0824AAA8: .4byte 0x00000403
_0824AAAC:
	ldr r0, _0824AAC0 @ =0x03005800
	ldr r1, [r0]
	ldrb r0, [r1]
	cmp r0, #1
	bne _0824AAC4
	adds r6, r1, #0
	adds r6, #0xf
	ldrb r0, [r4, #4]
	ldrb r1, [r1, #0xf]
	b _0824AAD2
	.align 2, 0
_0824AAC0: .4byte 0x03005800
_0824AAC4:
	adds r0, r3, #0
	adds r0, #0x10
	adds r6, r1, r0
	adds r1, #0x10
	adds r1, r1, r3
	ldrb r0, [r4, #4]
	ldrb r1, [r1]
_0824AAD2:
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, r5
	blo _0824AAFC
	ldr r2, _0824AAF8 @ =0x04000208
	ldrh r1, [r2]
	movs r0, #0
	strh r0, [r2]
	str r7, [r4, #8]
	subs r0, r3, r5
	strb r0, [r6]
	strh r5, [r4, #4]
	movs r0, #1
	strb r0, [r4, #2]
	strh r1, [r2]
	movs r0, #0
	b _0824AB00
	.align 2, 0
_0824AAF8: .4byte 0x04000208
_0824AAFC:
	movs r0, #0xa0
	lsls r0, r0, #3
_0824AB00:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0824ab08
FUN_0824ab08: @ 0x0824AB08
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0824AB26
	ldr r1, _0824AB2C @ =0x030057E0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldrh r1, [r2]
	ldr r0, _0824AB30 @ =0x00008024
	cmp r1, r0
	bne _0824AB26
	movs r0, #1
	strb r0, [r2, #2]
_0824AB26:
	pop {r0}
	bx r0
	.align 2, 0
_0824AB2C: .4byte 0x030057E0
_0824AB30: .4byte 0x00008024

	thumb_func_start FUN_0824ab34
FUN_0824ab34: @ 0x0824AB34
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _0824AB4A
	ldr r1, _0824AB50 @ =0x030057E0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	movs r0, #0
	strb r0, [r1, #0x12]
_0824AB4A:
	pop {r0}
	bx r0
	.align 2, 0
_0824AB50: .4byte 0x030057E0

	thumb_func_start FUN_0824ab54
FUN_0824ab54: @ 0x0824AB54
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _0824ABA0 @ =0x03005800
	ldr r2, [r0]
	ldrb r1, [r2]
	adds r4, r0, #0
	cmp r1, #0xff
	bne _0824AB68
	b _0824AC8E
_0824AB68:
	cmp r1, #1
	bne _0824ABF8
	ldrb r0, [r2, #4]
	ldrb r1, [r2, #5]
	adds r3, r0, #0
	orrs r3, r1
	ldrb r0, [r2, #6]
	orrs r3, r0
	cmp r3, #0
	bne _0824ABF8
	ldr r0, _0824ABA4 @ =0x03005804
	ldr r2, [r0]
	ldrb r1, [r2, #3]
	adds r4, r0, #0
	cmp r1, #0
	beq _0824AB90
	movs r0, #0x10
	strb r0, [r2, #8]
	ldr r0, [r4]
	strb r3, [r0, #7]
_0824AB90:
	ldr r1, [r4]
	ldrb r0, [r1, #8]
	cmp r0, #0
	beq _0824ABA8
	subs r0, #1
	strb r0, [r1, #8]
	b _0824ABAE
	.align 2, 0
_0824ABA0: .4byte 0x03005800
_0824ABA4: .4byte 0x03005804
_0824ABA8:
	ldrb r0, [r1, #7]
	adds r0, #1
	strb r0, [r1, #7]
_0824ABAE:
	ldr r1, [r4]
	ldrb r0, [r1, #8]
	cmp r0, #0
	bne _0824ABC0
	ldrb r1, [r1, #7]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _0824AC52
_0824ABC0:
	ldr r4, _0824ABE4 @ =0x03005808
	ldr r1, [r4]
	movs r0, #1
	str r0, [r1, #0x68]
	movs r0, #0xff
	str r0, [r1, #0x78]
	ldr r0, _0824ABE8 @ =0x0824AD41
	bl FUN_08247a78
	cmp r5, #0
	bne _0824ABEC
	ldr r0, [r4]
	adds r0, #0x68
	movs r1, #1
	bl FUN_08247d84
	b _0824AC8E
	.align 2, 0
_0824ABE4: .4byte 0x03005808
_0824ABE8: .4byte 0x0824AD41
_0824ABEC:
	ldr r0, [r4]
	adds r0, #0x68
	movs r1, #1
	bl FUN_08247dcc
	b _0824AC8E
_0824ABF8:
	ldr r0, [r4]
	ldrb r0, [r0, #0xe]
	cmp r0, #0
	bne _0824AC04
	bl FUN_0824ad68
_0824AC04:
	ldr r0, [r4]
	ldrb r0, [r0, #0xe]
	cmp r0, #0
	beq _0824AC52
	ldr r0, _0824AC30 @ =FUN_0824ac98
	bl FUN_08247a78
	cmp r5, #0
	beq _0824AC3C
	ldr r0, _0824AC34 @ =0x03005808
	ldr r0, [r0]
	adds r0, #0x68
	ldr r1, _0824AC38 @ =0x03005804
	ldr r1, [r1]
	ldr r1, [r1, #0x24]
	adds r1, #4
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl FUN_08247dcc
	b _0824AC8E
	.align 2, 0
_0824AC30: .4byte FUN_0824ac98
_0824AC34: .4byte 0x03005808
_0824AC38: .4byte 0x03005804
_0824AC3C:
	ldr r0, _0824AC74 @ =0x03005808
	ldr r0, [r0]
	adds r0, #0x68
	ldr r1, _0824AC78 @ =0x03005804
	ldr r1, [r1]
	ldr r1, [r1, #0x24]
	adds r1, #4
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl FUN_08247d84
_0824AC52:
	cmp r5, #0
	beq _0824AC8E
	ldr r0, _0824AC7C @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #1
	bne _0824AC84
	ldr r0, _0824AC80 @ =0x030057D0
	ldr r0, [r0]
	ldr r1, [r0, #0x1c]
	cmp r1, #0
	beq _0824AC8E
	movs r0, #0x27
	bl _call_via_r1
	b _0824AC8E
	.align 2, 0
_0824AC74: .4byte 0x03005808
_0824AC78: .4byte 0x03005804
_0824AC7C: .4byte 0x03005800
_0824AC80: .4byte 0x030057D0
_0824AC84:
	ldr r0, _0824AC94 @ =0x0824AD31
	bl FUN_08247a78
	bl FUN_08247e38
_0824AC8E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0824AC94: .4byte 0x0824AD31

	thumb_func_start FUN_0824ac98
FUN_0824ac98: @ 0x0824AC98
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	cmp r7, #0
	bne _0824AD02
	movs r6, #0
	ldr r0, _0824AD20 @ =0x00008020
	mov r8, r0
_0824ACAC:
	ldr r0, _0824AD24 @ =0x030057E0
	lsls r2, r6, #2
	adds r0, r2, r0
	ldr r1, [r0]
	ldrb r0, [r1, #2]
	cmp r0, #0
	beq _0824ACBE
	movs r0, #0
	strb r0, [r1, #2]
_0824ACBE:
	ldr r0, _0824AD28 @ =0x030057F0
	adds r0, r2, r0
	ldr r4, [r0]
	ldrh r0, [r4]
	cmp r0, r8
	bne _0824ACF8
	adds r0, r6, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0824a368
	ldr r5, _0824AD2C @ =0x03005800
	ldr r2, [r5]
	ldrb r1, [r4, #0x1a]
	ldrb r0, [r2, #4]
	bics r0, r1
	strb r0, [r2, #4]
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r3, [r0]
	cmp r3, #1
	bne _0824ACF4
	ldr r1, [r5]
	lsls r3, r6
	ldrb r0, [r1, #7]
	orrs r3, r0
	strb r3, [r1, #7]
_0824ACF4:
	movs r0, #0x26
	strh r0, [r4]
_0824ACF8:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #3
	bls _0824ACAC
_0824AD02:
	ldr r0, _0824AD2C @ =0x03005800
	ldr r1, [r0]
	ldrb r0, [r1, #0xe]
	movs r0, #0
	strb r0, [r1, #0xe]
	movs r0, #0x24
	adds r1, r7, #0
	bl FUN_08248f58
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0824AD20: .4byte 0x00008020
_0824AD24: .4byte 0x030057E0
_0824AD28: .4byte 0x030057F0
_0824AD2C: .4byte 0x03005800
_0824AD30:
	.byte 0x00, 0xB5, 0x09, 0x04, 0x09, 0x0C, 0x24, 0x20, 0xFE, 0xF7, 0x0E, 0xF9, 0x01, 0xBC, 0x00, 0x47
	.byte 0x00, 0xB5, 0x00, 0x06, 0x00, 0x0E, 0x09, 0x04, 0x09, 0x0C, 0x00, 0x29, 0x03, 0xD0, 0x24, 0x20
	.byte 0xFE, 0xF7, 0x02, 0xF9, 0x05, 0xE0, 0xFF, 0x28, 0x03, 0xD1, 0xFF, 0x20, 0x00, 0x21, 0xFE, 0xF7
	.byte 0xFB, 0xF8, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00

	thumb_func_start FUN_0824ad68
FUN_0824ad68: @ 0x0824AD68
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	ldr r0, _0824AE14 @ =0x03005800
	ldr r2, [r0]
	ldrb r0, [r2]
	cmp r0, #0xff
	bne _0824AD80
	b _0824AE84
_0824AD80:
	ldrb r0, [r2, #4]
	ldrb r1, [r2, #5]
	orrs r0, r1
	ldrb r1, [r2, #6]
	orrs r0, r1
	cmp r0, #0
	beq _0824AE84
	ldrb r0, [r2, #0xe]
	movs r0, #0
	strb r0, [r2, #0xe]
	mov r8, r0
	ldr r0, _0824AE18 @ =0x03005808
	ldr r0, [r0]
	adds r0, #0x6c
	str r0, [sp]
	movs r6, #0
	movs r0, #0x80
	lsls r0, r0, #8
	mov sb, r0
	ldr r1, _0824AE1C @ =0x00008024
	mov sl, r1
_0824ADAA:
	movs r5, #0
	ldr r0, _0824AE20 @ =0x030057F0
	lsls r7, r6, #2
	adds r4, r7, r0
	ldr r2, [r4]
	ldrh r1, [r2]
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	beq _0824ADCA
	adds r0, r6, #0
	mov r1, sp
	bl FUN_0824aea0
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_0824ADCA:
	ldr r2, [r4]
	ldrh r1, [r2, #0x34]
	mov r0, sb
	ands r0, r1
	cmp r0, #0
	beq _0824ADE6
	adds r2, #0x34
	adds r0, r6, #0
	mov r1, sp
	bl FUN_0824aea0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r5, r5, r0
_0824ADE6:
	ldr r0, _0824AE24 @ =0x030057E0
	adds r0, r7, r0
	ldr r0, [r0]
	ldrh r0, [r0]
	cmp r0, sl
	bne _0824AE00
	adds r0, r6, #0
	mov r1, sp
	bl FUN_0824b060
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r5, r5, r0
_0824AE00:
	cmp r5, #0
	beq _0824AE34
	ldr r0, _0824AE14 @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #1
	bne _0824AE28
	add r8, r5
	b _0824AE34
	.align 2, 0
_0824AE14: .4byte 0x03005800
_0824AE18: .4byte 0x03005808
_0824AE1C: .4byte 0x00008024
_0824AE20: .4byte 0x030057F0
_0824AE24: .4byte 0x030057E0
_0824AE28:
	adds r0, r7, r6
	adds r0, #8
	lsls r5, r0
	mov r2, r8
	orrs r2, r5
	mov r8, r2
_0824AE34:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #3
	bls _0824ADAA
	ldr r6, _0824AE94 @ =0x03005804
	mov r0, r8
	cmp r0, #0
	beq _0824AE7E
	ldr r2, [sp]
	movs r0, #3
	ands r0, r2
	ldr r5, _0824AE98 @ =0x03005800
	ldr r1, _0824AE9C @ =0x03005808
	cmp r0, #0
	beq _0824AE66
	movs r4, #0
	movs r3, #3
_0824AE58:
	strb r4, [r2]
	adds r0, r2, #1
	str r0, [sp]
	adds r2, r0, #0
	ands r0, r3
	cmp r0, #0
	bne _0824AE58
_0824AE66:
	ldr r0, [r1]
	mov r2, r8
	str r2, [r0, #0x68]
	ldr r0, [r5]
	ldrb r0, [r0]
	cmp r0, #0
	bne _0824AE7E
	ldr r0, [sp]
	subs r0, #0x6c
	ldr r1, [r1]
	subs r0, r0, r1
	mov r8, r0
_0824AE7E:
	ldr r0, [r6]
	mov r1, r8
	str r1, [r0, #0x24]
_0824AE84:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0824AE94: .4byte 0x03005804
_0824AE98: .4byte 0x03005800
_0824AE9C: .4byte 0x03005808

	thumb_func_start FUN_0824aea0
FUN_0824aea0: @ 0x0824AEA0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov ip, r1
	adds r4, r2, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sl, r0
	ldr r2, _0824AF1C @ =0x03005800
	ldr r0, [r2]
	ldrb r0, [r0]
	lsls r0, r0, #4
	ldr r1, _0824AF20 @ =0x085A8AE0
	adds r0, r0, r1
	mov r8, r0
	ldrh r1, [r4]
	ldr r0, _0824AF24 @ =0x00008022
	cmp r1, r0
	bne _0824AF0A
	adds r3, r4, #0
	adds r3, #0x20
	ldrb r1, [r3]
	lsls r1, r1, #2
	adds r5, r4, #4
	adds r1, r5, r1
	ldr r2, [r4, #0x28]
	ldr r0, [r4, #0x30]
	adds r2, r2, r0
	ldr r0, [r1]
	adds r6, r3, #0
	cmp r0, r2
	blo _0824AF0A
	movs r7, #0
_0824AEE8:
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bne _0824AEF8
	strb r7, [r6]
_0824AEF8:
	ldrb r1, [r3]
	lsls r1, r1, #2
	adds r1, r5, r1
	ldr r2, [r4, #0x28]
	ldr r0, [r4, #0x30]
	adds r2, r2, r0
	ldr r0, [r1]
	cmp r0, r2
	bhs _0824AEE8
_0824AF0A:
	ldrh r1, [r4]
	movs r0, #0x40
	ands r0, r1
	mov sb, r1
	cmp r0, #0
	beq _0824AF28
	movs r5, #0
	b _0824AF6C
	.align 2, 0
_0824AF1C: .4byte 0x03005800
_0824AF20: .4byte 0x085A8AE0
_0824AF24: .4byte 0x00008022
_0824AF28:
	ldr r0, _0824AF54 @ =0x00008022
	cmp sb, r0
	bne _0824AF5C
	adds r3, r4, #0
	adds r3, #0x20
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r1, r4, #4
	adds r1, r1, r0
	ldrh r7, [r4, #0x2e]
	ldr r5, [r1]
	adds r2, r5, r7
	ldr r1, [r4, #0x28]
	ldr r0, [r4, #0x30]
	adds r0, r1, r0
	adds r6, r3, #0
	cmp r2, r0
	bls _0824AF58
	subs r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	b _0824AF70
	.align 2, 0
_0824AF54: .4byte 0x00008022
_0824AF58:
	adds r5, r7, #0
	b _0824AF70
_0824AF5C:
	ldrh r2, [r4, #0x2e]
	ldr r0, [r4, #0x14]
	cmp r0, r2
	blo _0824AF68
	adds r5, r2, #0
	b _0824AF6C
_0824AF68:
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
_0824AF6C:
	adds r6, r4, #0
	adds r6, #0x20
_0824AF70:
	movs r3, #0xf
	mov r0, sb
	ands r3, r0
	mov r1, r8
	ldrb r1, [r1, #3]
	lsls r3, r1
	ldrb r0, [r4, #0x1f]
	mov r2, r8
	ldrb r2, [r2, #4]
	lsls r0, r2
	orrs r3, r0
	ldrb r1, [r6]
	adds r0, r1, #0
	mov r7, r8
	ldrb r7, [r7, #5]
	lsls r0, r7
	orrs r3, r0
	adds r0, r4, #0
	adds r0, #0x21
	adds r0, r0, r1
	ldrb r0, [r0]
	mov r1, r8
	ldrb r1, [r1, #6]
	lsls r0, r1
	orrs r3, r0
	orrs r3, r5
	str r3, [sp]
	ldr r2, _0824B02C @ =0x03005800
	ldr r0, [r2]
	ldrb r0, [r0]
	cmp r0, #1
	bne _0824AFB8
	ldrb r0, [r4, #0x1a]
	lsls r0, r0, #0x12
	orrs r3, r0
	str r3, [sp]
_0824AFB8:
	mov r2, sp
	movs r3, #0
	mov r7, r8
	ldrb r7, [r7]
	cmp r3, r7
	bhs _0824AFE2
_0824AFC4:
	mov r0, ip
	ldr r1, [r0]
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, #1
	adds r1, #1
	mov r7, ip
	str r1, [r7]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	mov r0, r8
	ldrb r0, [r0]
	cmp r3, r0
	blo _0824AFC4
_0824AFE2:
	cmp r5, #0
	beq _0824B002
	ldrb r1, [r6]
	lsls r1, r1, #2
	adds r0, r4, #4
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [sp, #4]
	ldr r0, _0824B030 @ =0x03005808
	ldr r1, [r0]
	add r0, sp, #4
	ldr r3, [r1, #4]
	mov r1, ip
	adds r2, r5, #0
	bl _call_via_r3
_0824B002:
	ldrh r1, [r4]
	ldr r0, _0824B034 @ =0x00008022
	cmp r1, r0
	bne _0824B01C
	ldrb r0, [r6]
	adds r0, #1
	strb r0, [r6]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bne _0824B01C
	movs r0, #0
	strb r0, [r6]
_0824B01C:
	ldr r0, _0824B02C @ =0x03005800
	ldr r2, [r0]
	ldrb r1, [r2]
	cmp r1, #1
	bne _0824B038
	ldrb r0, [r2, #0xe]
	strb r1, [r2, #0xe]
	b _0824B046
	.align 2, 0
_0824B02C: .4byte 0x03005800
_0824B030: .4byte 0x03005808
_0824B034: .4byte 0x00008022
_0824B038:
	movs r0, #1
	mov r1, sl
	lsls r0, r1
	ldrb r1, [r2, #0xe]
	orrs r0, r1
	ldrb r1, [r2, #0xe]
	strb r0, [r2, #0xe]
_0824B046:
	mov r2, r8
	ldrb r0, [r2]
	adds r0, r5, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0824b060
FUN_0824b060: @ 0x0824B060
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	ldr r1, _0824B088 @ =0x030057E0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	ldrb r0, [r4, #2]
	cmp r0, #0
	beq _0824B084
	ldrb r0, [r4, #3]
	cmp r0, #0
	bne _0824B08C
_0824B084:
	movs r0, #0
	b _0824B128
	.align 2, 0
_0824B088: .4byte 0x030057E0
_0824B08C:
	ldr r0, _0824B104 @ =0x03005800
	ldr r2, [r0]
	ldrb r0, [r2]
	lsls r0, r0, #4
	ldr r1, _0824B108 @ =0x085A8AE0
	adds r5, r0, r1
	ldrh r0, [r4]
	movs r1, #0xf
	ands r1, r0
	ldrb r0, [r5, #3]
	lsls r1, r0
	ldrh r0, [r4, #4]
	orrs r1, r0
	str r1, [sp]
	ldrb r0, [r2]
	cmp r0, #1
	bne _0824B0B6
	ldrb r0, [r4, #3]
	lsls r0, r0, #0x12
	orrs r1, r0
	str r1, [sp]
_0824B0B6:
	mov r2, sp
	movs r3, #0
	ldr r1, _0824B10C @ =0x03005808
	mov ip, r1
	add r7, sp, #4
	ldrb r0, [r5]
	cmp r3, r0
	bhs _0824B0DE
_0824B0C6:
	ldr r1, [r6]
	ldrb r0, [r2]
	strb r0, [r1]
	adds r2, #1
	adds r1, #1
	str r1, [r6]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	ldrb r1, [r5]
	cmp r3, r1
	blo _0824B0C6
_0824B0DE:
	ldr r0, [r4, #8]
	str r0, [sp, #4]
	mov r2, ip
	ldr r0, [r2]
	ldrh r2, [r4, #4]
	ldr r3, [r0, #4]
	adds r0, r7, #0
	adds r1, r6, #0
	bl _call_via_r3
	ldr r0, _0824B104 @ =0x03005800
	ldr r2, [r0]
	ldrb r0, [r2]
	cmp r0, #1
	bne _0824B110
	ldrb r0, [r2, #0xe]
	movs r0, #0x10
	b _0824B11C
	.align 2, 0
_0824B104: .4byte 0x03005800
_0824B108: .4byte 0x085A8AE0
_0824B10C: .4byte 0x03005808
_0824B110:
	movs r0, #0x10
	mov r1, r8
	lsls r0, r1
	ldrb r1, [r2, #0xe]
	orrs r0, r1
	ldrb r1, [r2, #0xe]
_0824B11C:
	strb r0, [r2, #0xe]
	ldrh r0, [r4, #4]
	ldrb r5, [r5]
	adds r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
_0824B128:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0824b134
FUN_0824b134: @ 0x0824B134
	push {r4, lr}
	ldr r0, _0824B168 @ =0x03005800
	ldr r4, [r0]
	ldrb r0, [r4]
	cmp r0, #0xff
	beq _0824B160
	ldr r2, _0824B16C @ =0x03005804
	ldr r3, [r2]
	ldrb r0, [r4, #4]
	ldrb r1, [r4, #5]
	orrs r0, r1
	ldrb r1, [r4, #6]
	orrs r0, r1
	movs r1, #0
	strb r0, [r3, #3]
	ldr r0, [r2]
	strb r1, [r0, #4]
	ldr r0, _0824B170 @ =FUN_0824b174
	bl FUN_08247a78
	bl FUN_08247e14
_0824B160:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0824B168: .4byte 0x03005800
_0824B16C: .4byte 0x03005804
_0824B170: .4byte FUN_0824b174

	thumb_func_start FUN_0824b174
FUN_0824b174: @ 0x0824B174
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	cmp r7, #0
	bne _0824B238
	ldr r0, _0824B1B0 @ =0x03005808
	ldr r0, [r0]
	adds r0, #0xdc
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	cmp r0, #0
	beq _0824B238
	ldr r0, _0824B1B4 @ =0x03005804
	ldr r0, [r0]
	strb r7, [r0, #1]
	ldr r0, _0824B1B8 @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0]
	cmp r0, #1
	bne _0824B1BC
	bl FUN_0824b260
	b _0824B1C0
	.align 2, 0
_0824B1B0: .4byte 0x03005808
_0824B1B4: .4byte 0x03005804
_0824B1B8: .4byte 0x03005800
_0824B1BC:
	bl FUN_0824b2f8
_0824B1C0:
	movs r6, #0
	ldr r0, _0824B250 @ =0x00008043
	mov r8, r0
	ldr r3, _0824B254 @ =0x03005800
_0824B1C8:
	ldr r0, _0824B258 @ =0x030057F0
	lsls r1, r6, #2
	adds r1, r1, r0
	ldr r4, [r1]
	ldrh r0, [r4, #0x34]
	cmp r0, r8
	bne _0824B21A
	ldr r0, _0824B25C @ =0x03005804
	ldr r0, [r0]
	ldrb r0, [r0, #1]
	asrs r0, r6
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0824B21A
	adds r5, r4, #0
	adds r5, #0x34
	adds r0, r4, #0
	adds r0, #0x61
	ldrb r2, [r0]
	cmp r2, #1
	bne _0824B1FE
	ldr r1, [r3]
	lsls r2, r6
	ldrb r0, [r1, #7]
	orrs r2, r0
	strb r2, [r1, #7]
_0824B1FE:
	adds r0, r6, #0
	movs r1, #1
	adds r2, r5, #0
	str r3, [sp]
	bl FUN_0824a368
	ldr r3, [sp]
	ldr r2, [r3]
	ldrb r1, [r5, #0x1a]
	ldrb r0, [r2, #5]
	bics r0, r1
	strb r0, [r2, #5]
	movs r0, #0x46
	strh r0, [r4, #0x34]
_0824B21A:
	adds r0, r6, #1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #3
	bls _0824B1C8
	ldr r0, _0824B25C @ =0x03005804
	ldr r1, [r0]
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _0824B238
	adds r7, r0, #0
	movs r1, #0xe0
	lsls r1, r1, #3
	adds r0, r1, #0
	orrs r7, r0
_0824B238:
	mov r0, sb
	adds r1, r7, #0
	bl FUN_08248f58
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0824B250: .4byte 0x00008043
_0824B254: .4byte 0x03005800
_0824B258: .4byte 0x030057F0
_0824B25C: .4byte 0x03005804

	thumb_func_start FUN_0824b260
FUN_0824b260: @ 0x0824B260
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	ldr r1, _0824B2F0 @ =0x03005808
	ldr r0, [r1]
	adds r0, #0xdc
	ldr r0, [r0]
	ldr r0, [r0, #4]
	lsrs r3, r0, #8
	movs r5, #0
	mov ip, r1
	movs r7, #0x1f
	ldr r4, _0824B2F4 @ =0x03005804
	movs r6, #1
_0824B27A:
	mov r0, sp
	adds r1, r0, r5
	adds r0, r3, #0
	ands r0, r7
	strb r0, [r1]
	lsrs r3, r3, #5
	cmp r0, #0
	bne _0824B296
	ldr r0, [r4]
	adds r1, r6, #0
	lsls r1, r5
	ldrb r2, [r0, #1]
	orrs r1, r2
	strb r1, [r0, #1]
_0824B296:
	adds r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bls _0824B27A
	mov r1, ip
	ldr r0, [r1]
	adds r0, #0xdc
	ldr r0, [r0]
	adds r6, r0, #0
	adds r6, #8
	movs r5, #0
_0824B2AE:
	mov r0, sp
	adds r1, r0, r5
	ldrb r0, [r1]
	adds r7, r5, #1
	cmp r0, #0
	beq _0824B2E0
	adds r4, r1, #0
_0824B2BC:
	ldrb r2, [r4]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_0824b350
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	adds r6, r6, r0
	ldrb r1, [r4]
	subs r1, r1, r0
	strb r1, [r4]
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _0824B2E0
	lsls r0, r1, #0x18
	cmp r0, #0
	bne _0824B2BC
_0824B2E0:
	lsls r0, r7, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #3
	bls _0824B2AE
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0824B2F0: .4byte 0x03005808
_0824B2F4: .4byte 0x03005804

	thumb_func_start FUN_0824b2f8
FUN_0824b2f8: @ 0x0824B2F8
	push {r4, r5, r6, lr}
	ldr r0, _0824B348 @ =0x03005808
	ldr r0, [r0]
	adds r0, #0xdc
	ldr r1, [r0]
	ldrh r0, [r1, #4]
	movs r4, #0x7f
	ands r4, r0
	adds r5, r1, #0
	adds r5, #8
	cmp r4, #0
	bne _0824B318
	ldr r0, _0824B34C @ =0x03005804
	ldr r1, [r0]
	movs r0, #0xf
	strb r0, [r1, #1]
_0824B318:
	movs r0, #0x80
	lsls r0, r0, #8
	adds r6, r0, #0
_0824B31E:
	cmp r4, #0
	beq _0824B340
	movs r0, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0824b350
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r5, r5, r0
	subs r0, r4, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r0, r4, #0
	ands r0, r6
	cmp r0, #0
	beq _0824B31E
_0824B340:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0824B348: .4byte 0x03005808
_0824B34C: .4byte 0x03005804

	thumb_func_start FUN_0824b350
FUN_0824b350: @ 0x0824B350
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r1, #0
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov ip, r0
	lsls r2, r2, #0x10
	lsrs r3, r2, #0x10
	ldr r2, _0824B384 @ =0x03005800
	ldr r0, [r2]
	ldrb r0, [r0]
	mvns r0, r0
	movs r1, #1
	ands r0, r1
	lsls r0, r0, #4
	ldr r1, _0824B388 @ =0x085A8AE0
	adds r6, r0, r1
	ldrb r0, [r6]
	cmp r3, r0
	bhs _0824B38C
	adds r0, r3, #0
	b _0824B57E
	.align 2, 0
_0824B384: .4byte 0x03005800
_0824B388: .4byte 0x085A8AE0
_0824B38C:
	movs r5, #0
	movs r4, #0
	ldrb r3, [r6, #1]
	ldrb r1, [r6, #7]
	mov r8, r1
	ldr r2, [sp]
	mov sb, r2
	cmp r4, r0
	bhs _0824B3B4
	adds r2, r0, #0
_0824B3A0:
	ldrb r0, [r7]
	lsls r1, r4, #3
	lsls r0, r1
	orrs r5, r0
	adds r7, #1
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, r2
	blo _0824B3A0
_0824B3B4:
	adds r0, r5, #0
	lsrs r0, r3
	mov r3, r8
	ands r0, r3
	ldr r1, _0824B48C @ =0xFFFFFF00
	mov sl, r1
	mov r3, sl
	mov r2, sb
	ands r3, r2
	orrs r3, r0
	str r3, [sp]
	adds r0, r5, #0
	ldrb r1, [r6, #2]
	lsrs r0, r1
	ldrb r1, [r6, #8]
	ands r0, r1
	lsls r0, r0, #8
	ldr r4, _0824B490 @ =0xFFFF00FF
	adds r2, r4, #0
	ands r2, r3
	orrs r2, r0
	str r2, [sp]
	adds r0, r5, #0
	ldrb r3, [r6, #3]
	lsrs r0, r3
	ldrb r1, [r6, #9]
	ands r0, r1
	lsls r0, r0, #0x10
	ldr r3, _0824B494 @ =0xFF00FFFF
	ands r3, r2
	orrs r3, r0
	str r3, [sp]
	adds r0, r5, #0
	ldrb r1, [r6, #4]
	lsrs r0, r1
	ldrb r1, [r6, #0xa]
	ands r0, r1
	lsls r0, r0, #0x18
	ldr r2, _0824B498 @ =0x00FFFFFF
	mov r8, r2
	mov r1, r8
	ands r1, r3
	orrs r1, r0
	mov r8, r1
	str r1, [sp]
	adds r1, r5, #0
	ldrb r2, [r6, #5]
	lsrs r1, r2
	ldrb r0, [r6, #0xb]
	ands r1, r0
	mov sb, sp
	ldr r2, [sp, #4]
	mov r3, sl
	ands r2, r3
	orrs r2, r1
	str r2, [sp, #4]
	adds r0, r5, #0
	ldrb r1, [r6, #6]
	lsrs r0, r1
	ldrb r1, [r6, #0xc]
	ands r0, r1
	lsls r0, r0, #8
	ands r4, r2
	orrs r4, r0
	str r4, [sp, #4]
	ldrh r0, [r6, #0xe]
	ands r5, r0
	lsls r1, r5, #0x10
	ldr r0, _0824B49C @ =0x0000FFFF
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #4]
	lsrs r0, r0, #0x10
	ldrb r6, [r6]
	adds r0, r0, r6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	mov r0, sp
	ldrb r0, [r0]
	cmp r0, #0
	beq _0824B45A
	b _0824B57C
_0824B45A:
	ldr r2, _0824B4A0 @ =0x03005800
	ldr r3, [r2]
	ldrb r2, [r3]
	cmp r2, #1
	bne _0824B518
	ldrb r0, [r3, #2]
	mov r5, ip
	asrs r0, r5
	ands r0, r2
	cmp r0, #0
	bne _0824B472
	b _0824B57C
_0824B472:
	mov r1, r8
	lsrs r0, r1, #0x10
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bne _0824B4A4
	mov r0, ip
	mov r1, sp
	adds r2, r7, #0
	bl FUN_0824b594
	b _0824B57C
	.align 2, 0
_0824B48C: .4byte 0xFFFFFF00
_0824B490: .4byte 0xFFFF00FF
_0824B494: .4byte 0xFF00FFFF
_0824B498: .4byte 0x00FFFFFF
_0824B49C: .4byte 0x0000FFFF
_0824B4A0: .4byte 0x03005800
_0824B4A4:
	mov r5, sb
	ldrb r0, [r5, #3]
	cmp r0, #0
	bne _0824B4B8
	mov r0, ip
	mov r1, sp
	adds r2, r7, #0
	bl FUN_0824b834
	b _0824B57C
_0824B4B8:
	movs r4, #0
	ldr r1, _0824B4D0 @ =0x030057F0
	ldr r0, [r1]
	ldrb r0, [r0, #0x1a]
	mov r5, ip
	asrs r0, r5
	ands r0, r2
	cmp r0, #0
	beq _0824B4D4
	ldrb r0, [r3, #4]
	b _0824B4FA
	.align 2, 0
_0824B4D0: .4byte 0x030057F0
_0824B4D4:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bhi _0824B57C
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldrb r0, [r0, #0x1a]
	mov r2, ip
	asrs r0, r2
	movs r2, #1
	ands r0, r2
	cmp r0, #0
	beq _0824B4D4
	ldr r3, _0824B514 @ =0x03005800
	ldr r0, [r3]
	ldrb r0, [r0, #4]
	mov r5, ip
_0824B4FA:
	asrs r0, r5
	ands r0, r2
	cmp r0, #0
	beq _0824B4D4
	cmp r4, #3
	bhi _0824B57C
	adds r0, r4, #0
	mov r1, ip
	mov r2, sp
	adds r3, r7, #0
	bl FUN_0824b648
	b _0824B57C
	.align 2, 0
_0824B514: .4byte 0x03005800
_0824B518:
	ldrb r1, [r3, #2]
	mov r2, sb
	ldrb r0, [r2, #1]
	adds r5, r1, #0
	ands r5, r0
	cmp r5, #0
	beq _0824B57C
	movs r4, #0
	movs r6, #1
_0824B52A:
	adds r0, r5, #0
	asrs r0, r4
	ands r0, r6
	cmp r0, #0
	beq _0824B572
	mov r1, sp
	ldrb r0, [r1, #2]
	cmp r0, #4
	bne _0824B546
	adds r0, r4, #0
	adds r2, r7, #0
	bl FUN_0824b594
	b _0824B572
_0824B546:
	ldrb r0, [r1, #3]
	cmp r0, #0
	bne _0824B558
	adds r0, r4, #0
	mov r1, sp
	adds r2, r7, #0
	bl FUN_0824b834
	b _0824B572
_0824B558:
	ldr r0, _0824B590 @ =0x03005800
	ldr r0, [r0]
	ldrb r0, [r0, #4]
	asrs r0, r4
	ands r0, r6
	cmp r0, #0
	beq _0824B572
	adds r0, r4, #0
	adds r1, r4, #0
	mov r2, sp
	adds r3, r7, #0
	bl FUN_0824b648
_0824B572:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _0824B52A
_0824B57C:
	mov r0, sl
_0824B57E:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0824B590: .4byte 0x03005800

	thumb_func_start FUN_0824b594
FUN_0824b594: @ 0x0824B594
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r1, #0
	str r2, [sp]
	lsls r0, r0, #0x18
	lsrs r7, r0, #0x18
	ldr r2, _0824B5C8 @ =0x030057E0
	lsls r1, r7, #2
	adds r1, r1, r2
	ldr r3, [r1]
	adds r5, r3, #0
	adds r5, #0xc
	movs r4, #0
	movs r0, #0
	strh r0, [r5, #2]
	ldr r0, [r1]
	ldr r0, [r0, #0x18]
	adds r1, r2, #0
	ldrh r2, [r6, #6]
	cmp r0, r2
	bhs _0824B5D0
	movs r0, #0x49
	strh r0, [r3, #0xc]
	ldr r0, _0824B5CC @ =0x00000701
	strh r0, [r5, #2]
	b _0824B61E
	.align 2, 0
_0824B5C8: .4byte 0x030057E0
_0824B5CC: .4byte 0x00000701
_0824B5D0:
	ldrb r0, [r5, #7]
	cmp r0, #0
	beq _0824B5E8
	ldrb r0, [r5, #6]
	cmp r0, #0
	beq _0824B5F4
	ldr r0, _0824B5E4 @ =0x00000709
	strh r0, [r5, #2]
	b _0824B61E
	.align 2, 0
_0824B5E4: .4byte 0x00000709
_0824B5E8:
	ldrb r0, [r5, #6]
	cmp r0, #0
	beq _0824B5F4
	movs r0, #0xe1
	lsls r0, r0, #3
	strh r0, [r5, #2]
_0824B5F4:
	movs r4, #0
	ldr r0, _0824B63C @ =0x00008042
	strh r0, [r5]
	ldrh r0, [r6, #6]
	strh r0, [r5, #4]
	ldrh r2, [r6, #6]
	lsls r0, r7, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #0x14]
	str r0, [sp, #4]
	ldr r0, _0824B640 @ =0x03005808
	ldr r0, [r0]
	add r1, sp, #4
	ldr r3, [r0, #4]
	mov r0, sp
	bl _call_via_r3
	movs r0, #1
	strb r0, [r5, #6]
	strh r4, [r5]
_0824B61E:
	ldrh r0, [r5, #2]
	cmp r0, #0
	beq _0824B632
	ldr r0, _0824B644 @ =0x03005804
	ldr r2, [r0]
	movs r0, #0x10
	lsls r0, r7
	ldrb r1, [r2, #4]
	orrs r0, r1
	strb r0, [r2, #4]
_0824B632:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0824B63C: .4byte 0x00008042
_0824B640: .4byte 0x03005808
_0824B644: .4byte 0x03005804

	thumb_func_start FUN_0824b648
FUN_0824b648: @ 0x0824B648
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r2, #0
	lsls r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov sl, r1
	ldr r1, _0824B714 @ =0x030057F0
	lsrs r0, r0, #0x16
	adds r0, r0, r1
	ldr r0, [r0]
	mov ip, r0
	ldrh r0, [r0]
	mov sb, r0
	mov r0, ip
	adds r0, #0x21
	ldrb r2, [r6, #4]
	adds r0, r0, r2
	ldrb r0, [r0]
	str r0, [sp]
	ldrb r2, [r6, #2]
	cmp r2, #2
	bne _0824B684
	ldr r0, _0824B718 @ =0x00008022
	cmp sb, r0
	beq _0824B69E
_0824B684:
	cmp r2, #1
	bne _0824B68E
	ldr r0, _0824B71C @ =0x00008021
	cmp sb, r0
	beq _0824B69E
_0824B68E:
	movs r3, #0x1b
	add r3, ip
	mov r8, r3
	cmp r2, #3
	bne _0824B6C2
	ldr r0, _0824B720 @ =0x00008023
	cmp sb, r0
	bne _0824B6C2
_0824B69E:
	ldrb r1, [r6, #4]
	mov r0, ip
	adds r0, #0x21
	adds r0, r0, r1
	ldrb r0, [r0]
	movs r7, #0x1b
	add r7, ip
	mov r8, r7
	ldrb r2, [r6, #5]
	cmp r0, r2
	bne _0824B6C2
	adds r0, r7, r1
	movs r1, #1
	mov r3, sl
	lsls r1, r3
	ldrb r2, [r0]
	orrs r1, r2
	strb r1, [r0]
_0824B6C2:
	ldrb r2, [r6, #4]
	mov r7, r8
	adds r0, r7, r2
	ldrb r0, [r0]
	mov r3, ip
	ldrb r1, [r3, #0x1a]
	ands r0, r1
	cmp r0, r1
	bne _0824B7BE
	adds r3, #0x21
	adds r2, r3, r2
	ldrb r0, [r2]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	ldrb r0, [r6, #4]
	add r0, r8
	strb r1, [r0]
	mov r7, ip
	ldrh r1, [r7]
	ldr r2, _0824B724 @ =0x00007FDF
	adds r0, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r5, r3, #0
	cmp r0, #1
	bhi _0824B7B0
	ldr r0, _0824B71C @ =0x00008021
	cmp r1, r0
	bne _0824B728
	ldrb r1, [r6, #4]
	lsls r1, r1, #2
	subs r3, #0x1d
	adds r1, r3, r1
	ldrh r2, [r7, #0x2e]
	ldr r0, [r1]
	adds r0, r0, r2
	str r0, [r1]
	b _0824B73E
	.align 2, 0
_0824B714: .4byte 0x030057F0
_0824B718: .4byte 0x00008022
_0824B71C: .4byte 0x00008021
_0824B720: .4byte 0x00008023
_0824B724: .4byte 0x00007FDF
_0824B728:
	ldrb r2, [r6, #4]
	lsls r2, r2, #2
	mov r3, ip
	adds r3, #4
	adds r2, r3, r2
	mov r7, ip
	ldrh r1, [r7, #0x2e]
	lsls r1, r1, #2
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
_0824B73E:
	mov r0, ip
	ldrh r1, [r0, #0x2e]
	ldr r0, [r0, #0x14]
	subs r0, r0, r1
	mov r1, ip
	str r0, [r1, #0x14]
	cmp r0, #0
	beq _0824B752
	cmp r0, #0
	bge _0824B7BE
_0824B752:
	mov r0, ip
	adds r0, #0x20
	movs r2, #0
	strb r2, [r0]
	mov r7, ip
	ldrh r1, [r7]
	ldr r0, _0824B794 @ =0x00008021
	cmp r1, r0
	bne _0824B79C
	movs r4, #0
_0824B766:
	adds r0, r5, r4
	movs r1, #1
	strb r1, [r0]
	lsls r1, r4, #2
	adds r1, r3, r1
	mov r2, ip
	ldrh r0, [r2, #0x2e]
	adds r2, r0, #0
	muls r2, r4, r2
	mov r7, ip
	ldr r0, [r7, #0x28]
	adds r0, r0, r2
	str r0, [r1]
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	cmp r4, #3
	bls _0824B766
	ldr r0, [r7, #0x30]
	str r0, [r7, #0x14]
	ldr r0, _0824B798 @ =0x00008022
	strh r0, [r7]
	b _0824B7BE
	.align 2, 0
_0824B794: .4byte 0x00008021
_0824B798: .4byte 0x00008022
_0824B79C:
	strb r2, [r5]
	mov r0, ip
	str r2, [r0, #0x14]
	ldr r0, _0824B7AC @ =0x00008023
	mov r1, ip
	strh r0, [r1]
	b _0824B7BE
	.align 2, 0
_0824B7AC: .4byte 0x00008023
_0824B7B0:
	lsls r1, r1, #0x10
	ldr r0, _0824B820 @ =0x80230000
	cmp r1, r0
	bne _0824B7BE
	ldr r0, _0824B824 @ =0x00008020
	mov r2, ip
	strh r0, [r2]
_0824B7BE:
	mov r3, ip
	ldrh r0, [r3]
	cmp r0, sb
	bne _0824B7E8
	ldrb r2, [r6, #4]
	mov r0, ip
	adds r0, #0x21
	adds r0, r0, r2
	ldrb r0, [r0]
	ldr r7, [sp]
	cmp r0, r7
	bne _0824B7E8
	mov r1, r8
	adds r0, r1, r2
	ldrb r0, [r0]
	mov r2, sl
	asrs r0, r2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0824B80E
_0824B7E8:
	ldr r4, _0824B828 @ =0x04000208
	ldrh r2, [r4]
	movs r0, #0
	strh r0, [r4]
	ldr r0, _0824B82C @ =0x03005804
	ldr r3, [r0]
	movs r0, #0x10
	mov r7, sl
	lsls r0, r7
	ldrb r1, [r3, #2]
	orrs r0, r1
	movs r1, #0
	strb r0, [r3, #2]
	lsls r0, r7, #2
	ldr r3, _0824B830 @ =0x030057F0
	adds r0, r0, r3
	ldr r0, [r0]
	strh r1, [r0, #2]
	strh r2, [r4]
_0824B80E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0824B820: .4byte 0x80230000
_0824B824: .4byte 0x00008020
_0824B828: .4byte 0x04000208
_0824B82C: .4byte 0x03005804
_0824B830: .4byte 0x030057F0

	thumb_func_start FUN_0824b834
FUN_0824b834: @ 0x0824B834
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r1, #0
	str r2, [sp]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov r8, r0
	movs r7, #0
	ldr r1, _0824B894 @ =0x030057F0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	adds r5, r4, #0
	adds r5, #0x34
	ldrh r0, [r4, #0x34]
	mov sb, r0
	ldrb r0, [r6, #4]
	adds r3, r4, #0
	adds r3, #0x55
	adds r0, r3, r0
	ldrb r0, [r0]
	mov sl, r0
	ldrb r0, [r6, #2]
	cmp r0, #3
	bne _0824B8A4
	ldr r0, _0824B898 @ =0x03005804
	ldr r2, [r0]
	movs r0, #1
	mov r1, r8
	lsls r0, r1
	ldrb r1, [r2, #1]
	orrs r0, r1
	strb r0, [r2, #1]
	ldrh r1, [r4, #0x34]
	ldr r0, _0824B89C @ =0x00008042
	cmp r1, r0
	bne _0824B8EA
	adds r0, r4, #0
	adds r0, #0x54
	strb r7, [r0]
	strb r7, [r3]
	ldr r0, _0824B8A0 @ =0x00008043
	strh r0, [r4, #0x34]
	b _0824B8EA
	.align 2, 0
_0824B894: .4byte 0x030057F0
_0824B898: .4byte 0x03005804
_0824B89C: .4byte 0x00008042
_0824B8A0: .4byte 0x00008043
_0824B8A4:
	cmp r0, #2
	bne _0824B8D0
	ldr r0, _0824B8C8 @ =0x00008041
	cmp sb, r0
	bne _0824B8BC
	ldr r0, [r5, #0x14]
	cmp r0, #0
	bne _0824B8BC
	mov r0, r8
	adds r1, r5, #0
	bl FUN_0824ba40
_0824B8BC:
	ldrh r1, [r5]
	ldr r0, _0824B8CC @ =0x00008042
	cmp r1, r0
	bne _0824B8EA
	b _0824B8EE
	.align 2, 0
_0824B8C8: .4byte 0x00008041
_0824B8CC: .4byte 0x00008042
_0824B8D0:
	cmp r0, #1
	bne _0824B8EA
	ldr r7, _0824B99C @ =0x00008041
	cmp sb, r7
	beq _0824B8EE
	mov r0, r8
	adds r1, r5, #0
	bl FUN_0824b9b0
	ldrh r0, [r4, #0x34]
	cmp r0, r7
	bne _0824B98A
	movs r7, #1
_0824B8EA:
	cmp r7, #0
	beq _0824B944
_0824B8EE:
	ldrb r2, [r6, #5]
	ldrb r3, [r6, #4]
	adds r4, r5, #0
	adds r4, #0x21
	adds r0, r4, r3
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	cmp r2, r0
	bne _0824B944
	ldr r0, _0824B9A0 @ =0x03005808
	ldr r0, [r0]
	lsls r1, r3, #2
	adds r1, #4
	adds r1, r5, r1
	ldrh r2, [r6, #6]
	ldr r3, [r0, #4]
	mov r0, sp
	bl _call_via_r3
	ldrh r1, [r5]
	ldr r0, _0824B9A4 @ =0x00008042
	cmp r1, r0
	bne _0824B934
	ldrb r0, [r6, #4]
	lsls r0, r0, #2
	adds r2, r5, #4
	adds r2, r2, r0
	ldrh r0, [r5, #0x2e]
	lsls r1, r0, #1
	adds r1, r1, r0
	ldr r0, [r2]
	adds r0, r0, r1
	str r0, [r2]
_0824B934:
	ldrh r1, [r6, #6]
	ldr r0, [r5, #0x14]
	subs r0, r0, r1
	str r0, [r5, #0x14]
	ldrb r0, [r6, #4]
	adds r0, r4, r0
	ldrb r1, [r6, #5]
	strb r1, [r0]
_0824B944:
	ldrh r0, [r5, #0x18]
	cmp r0, #0
	bne _0824B98A
	ldrb r0, [r6, #4]
	adds r1, r5, #0
	adds r1, #0x20
	strb r0, [r1]
	ldrh r0, [r5]
	cmp r0, sb
	bne _0824B96C
	adds r0, r5, #0
	adds r0, #0x21
	ldrb r2, [r6, #4]
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, sl
	bne _0824B96C
	ldrb r6, [r6, #5]
	cmp r0, r6
	bne _0824B98A
_0824B96C:
	ldr r3, _0824B9A8 @ =0x04000208
	ldrh r2, [r3]
	movs r0, #0
	strh r0, [r3]
	ldr r0, _0824B9AC @ =0x03005804
	ldr r4, [r0]
	movs r0, #1
	mov r1, r8
	lsls r0, r1
	ldrb r1, [r4, #2]
	orrs r0, r1
	movs r1, #0
	strb r0, [r4, #2]
	strh r1, [r5, #2]
	strh r2, [r3]
_0824B98A:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0824B99C: .4byte 0x00008041
_0824B9A0: .4byte 0x03005808
_0824B9A4: .4byte 0x00008042
_0824B9A8: .4byte 0x04000208
_0824B9AC: .4byte 0x03005804

	thumb_func_start FUN_0824b9b0
FUN_0824b9b0: @ 0x0824B9B0
	push {r4, r5, r6, r7, lr}
	adds r2, r1, #0
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	ldr r0, _0824B9CC @ =0x03005800
	ldr r3, [r0]
	ldrb r1, [r3]
	mov ip, r0
	cmp r1, #1
	bne _0824B9D0
	movs r5, #3
	adds r1, r3, #0
	adds r1, #0xf
	b _0824B9D8
	.align 2, 0
_0824B9CC: .4byte 0x03005800
_0824B9D0:
	movs r5, #2
	adds r0, r4, #0
	adds r0, #0x10
	adds r1, r3, r0
_0824B9D8:
	movs r7, #1
	adds r0, r7, #0
	lsls r0, r4
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	adds r4, r6, #0
	ldrh r3, [r2]
	cmp r3, #0
	bne _0824BA36
	ldrb r0, [r1]
	cmp r0, r5
	bhs _0824BA10
	movs r0, #0x49
	strh r0, [r2]
	ldr r0, _0824BA08 @ =0x00000702
	strh r0, [r2, #0x18]
	ldr r0, _0824BA0C @ =0x03005804
	ldr r2, [r0]
	ldrb r1, [r2, #4]
	adds r0, r6, #0
	orrs r0, r1
	strb r0, [r2, #4]
	b _0824BA36
	.align 2, 0
_0824BA08: .4byte 0x00000702
_0824BA0C: .4byte 0x03005804
_0824BA10:
	strh r3, [r2, #0x18]
	ldrb r0, [r1]
	subs r0, r0, r5
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x2d
	str r0, [r2, #4]
	movs r0, #7
	str r0, [r2, #0x14]
	strb r7, [r2, #0x1f]
	strh r3, [r2, #0x2e]
	strb r4, [r2, #0x1a]
	ldr r0, _0824BA3C @ =0x00008041
	strh r0, [r2]
	mov r0, ip
	ldr r1, [r0]
	ldrb r0, [r1, #5]
	orrs r4, r0
	strb r4, [r1, #5]
_0824BA36:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0824BA3C: .4byte 0x00008041

	thumb_func_start FUN_0824ba40
FUN_0824ba40: @ 0x0824BA40
	push {r4, r5, r6, r7, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	adds r0, r4, #0
	adds r0, #0x2d
	ldrb r0, [r0]
	cmp r0, #1
	bne _0824BA64
	ldr r0, _0824BA60 @ =0x03005800
	lsls r1, r5, #5
	adds r1, #0x14
	ldr r0, [r0]
	adds r0, r0, r1
	adds r0, #4
	b _0824BABA
	.align 2, 0
_0824BA60: .4byte 0x03005800
_0824BA64:
	ldr r1, _0824BAA8 @ =0x030057F0
	lsls r0, r5, #2
	adds r0, r0, r1
	ldr r2, [r0]
	ldr r1, [r4, #0x30]
	ldr r0, [r2, #0x6c]
	cmp r1, r0
	bls _0824BAB8
	movs r1, #0x80
	lsls r1, r1, #0x11
	lsls r1, r5
	lsrs r1, r1, #0x18
	ldr r0, _0824BAAC @ =0x03005804
	ldr r3, [r0]
	ldrb r2, [r3, #4]
	adds r0, r1, #0
	orrs r0, r2
	strb r0, [r3, #4]
	ldr r0, _0824BAB0 @ =0x03005800
	ldr r2, [r0]
	ldrb r0, [r2, #5]
	bics r0, r1
	strb r0, [r2, #5]
	ldr r0, _0824BAB4 @ =0x00000701
	strh r0, [r4, #0x18]
	movs r0, #0x47
	strh r0, [r4]
	adds r0, r5, #0
	movs r1, #1
	adds r2, r4, #0
	bl FUN_0824a368
	b _0824BAEC
	.align 2, 0
_0824BAA8: .4byte 0x030057F0
_0824BAAC: .4byte 0x03005804
_0824BAB0: .4byte 0x03005800
_0824BAB4: .4byte 0x00000701
_0824BAB8:
	ldr r0, [r2, #0x68]
_0824BABA:
	str r0, [r4, #4]
	movs r3, #0
	adds r6, r4, #0
	adds r6, #0x21
	movs r7, #0
	adds r5, r4, #4
_0824BAC6:
	adds r0, r6, r3
	strb r7, [r0]
	lsls r1, r3, #2
	adds r1, r5, r1
	ldrh r0, [r4, #0x2e]
	adds r2, r0, #0
	muls r2, r3, r2
	ldr r0, [r4, #4]
	adds r0, r0, r2
	str r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #3
	bls _0824BAC6
	ldr r0, [r4, #0x30]
	str r0, [r4, #0x14]
	ldr r0, _0824BAF4 @ =0x00008042
	strh r0, [r4]
_0824BAEC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0824BAF4: .4byte 0x00008042

	thumb_func_start FUN_0824baf8
FUN_0824baf8: @ 0x0824BAF8
	push {r4, r5, r6, r7, lr}
	ldr r2, _0824BB84 @ =0x03005800
	ldr r0, [r2]
	ldrb r1, [r0, #4]
	ldrb r0, [r0, #5]
	orrs r0, r1
	cmp r0, #0
	beq _0824BB7E
	ldr r1, _0824BB88 @ =0x04000208
	ldrh r0, [r1]
	mov ip, r0
	movs r0, #0
	strh r0, [r1]
	ldr r1, _0824BB8C @ =0x03005804
	ldr r0, [r1]
	ldrb r0, [r0, #2]
	lsrs r7, r0, #4
	movs r3, #0
	adds r6, r1, #0
	adds r5, r2, #0
	ldr r4, _0824BB90 @ =0x030057F0
_0824BB22:
	movs r0, #0x80
	lsls r0, r0, #0x11
	lsls r0, r3
	lsrs r2, r0, #0x18
	ldr r0, [r5]
	ldrb r0, [r0, #4]
	ands r0, r2
	cmp r0, #0
	beq _0824BB4A
	ldr r0, [r6]
	ldrb r0, [r0, #2]
	ands r0, r2
	cmp r0, #0
	bne _0824BB4A
	lsls r0, r3, #2
	adds r0, r0, r4
	ldr r1, [r0]
	ldrh r0, [r1, #2]
	adds r0, #1
	strh r0, [r1, #2]
_0824BB4A:
	ldr r0, [r5]
	ldrb r0, [r0, #5]
	ands r0, r2
	cmp r0, #0
	beq _0824BB68
	adds r0, r7, #0
	ands r0, r2
	cmp r0, #0
	bne _0824BB68
	lsls r0, r3, #2
	adds r0, r0, r4
	ldr r1, [r0]
	ldrh r0, [r1, #0x36]
	adds r0, #1
	strh r0, [r1, #0x36]
_0824BB68:
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #3
	bls _0824BB22
	ldr r0, [r6]
	movs r1, #0
	strb r1, [r0, #2]
	ldr r0, _0824BB88 @ =0x04000208
	mov r1, ip
	strh r1, [r0]
_0824BB7E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0824BB84: .4byte 0x03005800
_0824BB88: .4byte 0x04000208
_0824BB8C: .4byte 0x03005804
_0824BB90: .4byte 0x030057F0

	thumb_func_start FUN_0824bb94
FUN_0824bb94: @ 0x0824BB94
	push {lr}
	ldr r0, _0824BBA8 @ =FUN_08248f58
	bl FUN_08247a78
	movs r0, #1
	movs r1, #0
	bl FUN_08247f40
	pop {r0}
	bx r0
	.align 2, 0
_0824BBA8: .4byte FUN_08248f58

	thumb_func_start FUN_0824bbac
FUN_0824bbac: @ 0x0824BBAC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldr r0, _0824BBC4 @ =0x04000208
	ldrh r0, [r0]
	cmp r0, #0
	bne _0824BBC8
	movs r0, #1
	rsbs r0, r0, #0
	b _0824BC48
	.align 2, 0
_0824BBC4: .4byte 0x04000208
_0824BBC8:
	ldr r0, _0824BBF4 @ =0x04000200
	ldrh r0, [r0]
	mov r8, r0
	ldr r4, _0824BBF8 @ =0x030057D0
	ldr r1, [r4]
	movs r0, #0xa
	str r0, [r1]
	ldr r0, _0824BBFC @ =FUN_0824bdc8
	bl FUN_08247a90
	bl FUN_0824bc60
	ldr r0, [r4]
	ldrb r0, [r0, #0xa]
	lsls r0, r0, #2
	ldr r1, _0824BC00 @ =0x04000100
	adds r4, r0, r1
	lsls r0, r5, #0x1b
	lsrs r5, r0, #0x18
	movs r7, #0
	b _0824BC16
	.align 2, 0
_0824BBF4: .4byte 0x04000200
_0824BBF8: .4byte 0x030057D0
_0824BBFC: .4byte FUN_0824bdc8
_0824BC00: .4byte 0x04000100
_0824BC04:
	strh r6, [r4, #2]
	strh r6, [r4]
	movs r0, #0x83
	strh r0, [r4, #2]
_0824BC0C:
	ldrh r0, [r4]
	cmp r0, #0x1f
	bls _0824BC0C
	strh r7, [r4, #2]
	strh r7, [r4]
_0824BC16:
	subs r0, r5, #1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0xff
	beq _0824BC2A
	bl FUN_0824bcd4
	adds r6, r0, #0
	cmp r6, #0
	beq _0824BC04
_0824BC2A:
	ldr r1, _0824BC54 @ =0x04000208
	movs r0, #0
	strh r0, [r1]
	ldr r0, _0824BC58 @ =0x04000200
	mov r2, r8
	strh r2, [r0]
	movs r0, #1
	strh r0, [r1]
	ldr r0, _0824BC5C @ =0x030057D0
	ldr r1, [r0]
	movs r0, #0
	str r0, [r1]
	bl FUN_08247a90
	adds r0, r6, #0
_0824BC48:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0824BC54: .4byte 0x04000208
_0824BC58: .4byte 0x04000200
_0824BC5C: .4byte 0x030057D0

	thumb_func_start FUN_0824bc60
FUN_0824bc60: @ 0x0824BC60
	push {r4, r5, lr}
	sub sp, #4
	ldr r3, _0824BCB8 @ =0x04000208
	movs r4, #0
	strh r4, [r3]
	ldr r2, _0824BCBC @ =0x04000200
	ldr r0, _0824BCC0 @ =0x030057D0
	ldr r0, [r0]
	movs r1, #8
	ldrb r0, [r0, #0xa]
	lsls r1, r0
	movs r5, #0x80
	orrs r1, r5
	ldrh r0, [r2]
	bics r0, r1
	strh r0, [r2]
	movs r0, #1
	strh r0, [r3]
	ldr r0, _0824BCC4 @ =0x04000134
	strh r4, [r0]
	subs r2, #0xd8
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r2]
	ldrh r0, [r2]
	movs r3, #0x81
	lsls r3, r3, #7
	adds r1, r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r0, #0
	str r0, [sp]
	ldr r1, _0824BCC8 @ =0x03005810
	ldr r2, _0824BCCC @ =0x05000003
	mov r0, sp
	bl CpuSet
	ldr r0, _0824BCD0 @ =0x04000202
	strh r5, [r0]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0824BCB8: .4byte 0x04000208
_0824BCBC: .4byte 0x04000200
_0824BCC0: .4byte 0x030057D0
_0824BCC4: .4byte 0x04000134
_0824BCC8: .4byte 0x03005810
_0824BCCC: .4byte 0x05000003
_0824BCD0: .4byte 0x04000202

	thumb_func_start FUN_0824bcd4
FUN_0824bcd4: @ 0x0824BCD4
	push {r4, r5, r6, r7, lr}
	ldr r0, _0824BCE8 @ =0x03005810
	ldrb r1, [r0, #1]
	mov ip, r1
	adds r7, r0, #0
	cmp r1, #0
	beq _0824BCEC
	cmp r1, #1
	beq _0824BD24
	b _0824BDBC
	.align 2, 0
_0824BCE8: .4byte 0x03005810
_0824BCEC:
	movs r6, #1
	strb r6, [r7]
	ldr r3, _0824BD18 @ =0x04000128
	ldrh r0, [r3]
	movs r5, #1
	orrs r0, r5
	strh r0, [r3]
	ldr r4, _0824BD1C @ =0x04000208
	mov r0, ip
	strh r0, [r4]
	ldr r2, _0824BD20 @ =0x04000200
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	strh r6, [r4]
	strb r5, [r7, #1]
	ldrb r0, [r3]
	orrs r0, r1
	strb r0, [r3]
	b _0824BDC0
	.align 2, 0
_0824BD18: .4byte 0x04000128
_0824BD1C: .4byte 0x04000208
_0824BD20: .4byte 0x04000200
_0824BD24:
	ldrh r0, [r7, #0xa]
	cmp r0, #0
	bne _0824BDB8
	ldrb r0, [r7]
	cmp r0, #1
	bne _0824BD54
	ldrh r0, [r7, #2]
	cmp r0, #0
	bne _0824BDC0
	ldr r3, _0824BD4C @ =0x04000208
	strh r0, [r3]
	ldr r2, _0824BD50 @ =0x04000128
	ldrh r0, [r2]
	movs r1, #0x80
	orrs r0, r1
	strh r0, [r2]
	mov r1, ip
	strh r1, [r3]
	b _0824BDC0
	.align 2, 0
_0824BD4C: .4byte 0x04000208
_0824BD50: .4byte 0x04000128
_0824BD54:
	ldrh r1, [r7, #4]
	ldr r0, _0824BDA0 @ =0x00008001
	cmp r1, r0
	beq _0824BDC0
	ldrh r6, [r7, #2]
	cmp r6, #0
	bne _0824BDC0
	ldr r4, _0824BDA4 @ =0x04000208
	strh r6, [r4]
	ldr r3, _0824BDA8 @ =0x04000200
	ldrh r1, [r3]
	ldr r0, _0824BDAC @ =0x0000FF7F
	ands r0, r1
	strh r0, [r3]
	mov r7, ip
	strh r7, [r4]
	ldr r2, _0824BDB0 @ =0x04000128
	strh r6, [r2]
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r1, #0
	strh r0, [r2]
	ldr r0, _0824BDB4 @ =0x04000202
	movs r5, #0x80
	strh r5, [r0]
	ldrh r0, [r2]
	movs r7, #0x81
	lsls r7, r7, #7
	adds r1, r7, #0
	orrs r0, r1
	strh r0, [r2]
	strh r6, [r4]
	ldrh r0, [r3]
	orrs r0, r5
	strh r0, [r3]
	mov r0, ip
	strh r0, [r4]
	b _0824BDC0
	.align 2, 0
_0824BDA0: .4byte 0x00008001
_0824BDA4: .4byte 0x04000208
_0824BDA8: .4byte 0x04000200
_0824BDAC: .4byte 0x0000FF7F
_0824BDB0: .4byte 0x04000128
_0824BDB4: .4byte 0x04000202
_0824BDB8:
	movs r0, #2
	strb r0, [r7, #1]
_0824BDBC:
	ldrh r0, [r7, #0xa]
	b _0824BDC2
_0824BDC0:
	movs r0, #0
_0824BDC2:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0824bdc8
FUN_0824bdc8: @ 0x0824BDC8
	push {r4, r5, lr}
	ldr r0, _0824BE10 @ =0x04000120
	ldr r5, [r0]
	ldr r0, _0824BE14 @ =0x03005810
	ldrb r1, [r0]
	adds r4, r0, #0
	cmp r1, #1
	beq _0824BDE2
	ldr r0, _0824BE18 @ =0x04000128
	ldrh r1, [r0]
	movs r2, #0x80
	orrs r1, r2
	strh r1, [r0]
_0824BDE2:
	ldrb r2, [r4]
	lsls r1, r2, #4
	adds r0, r5, #0
	lsls r0, r1
	lsrs r1, r0, #0x10
	movs r0, #1
	subs r0, r0, r2
	lsls r0, r0, #4
	lsls r5, r0
	adds r0, r5, #0
	lsrs r5, r0, #0x10
	ldrh r0, [r4, #0xa]
	cmp r0, #0
	bne _0824BE36
	ldrh r2, [r4, #6]
	cmp r1, r2
	bne _0824BE34
	ldrh r3, [r4, #2]
	cmp r3, #3
	bls _0824BE1C
	strh r5, [r4, #0xa]
	b _0824BE36
	.align 2, 0
_0824BE10: .4byte 0x04000120
_0824BE14: .4byte 0x03005810
_0824BE18: .4byte 0x04000128
_0824BE1C:
	ldrh r0, [r4, #4]
	mvns r0, r0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r1, r0
	bne _0824BE36
	mvns r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r5, r0
	bne _0824BE36
	adds r0, r3, #1
_0824BE34:
	strh r0, [r4, #2]
_0824BE36:
	ldrh r0, [r4, #2]
	cmp r0, #3
	bhi _0824BE4C
	lsls r0, r0, #1
	ldr r1, _0824BE48 @ =0x085A8B18
	adds r0, r0, r1
	ldrh r0, [r0]
	b _0824BE4E
	.align 2, 0
_0824BE48: .4byte 0x085A8B18
_0824BE4C:
	ldr r0, _0824BEA4 @ =0x00008001
_0824BE4E:
	strh r0, [r4, #4]
	mvns r0, r5
	strh r0, [r4, #6]
	ldr r3, _0824BEA8 @ =0x04000120
	ldrh r2, [r4, #4]
	ldrb r1, [r4]
	movs r0, #1
	subs r0, r0, r1
	lsls r0, r0, #4
	lsls r2, r0
	ldrh r0, [r4, #6]
	lsls r1, r1, #4
	lsls r0, r1
	adds r2, r2, r0
	str r2, [r3]
	ldrb r0, [r4]
	cmp r0, #1
	bne _0824BE9C
	ldrh r0, [r4, #2]
	cmp r0, #0
	bne _0824BE7E
	ldr r0, _0824BEAC @ =0x0000494E
	cmp r5, r0
	bne _0824BE9C
_0824BE7E:
	movs r0, #0
	ldr r1, _0824BEB0 @ =0x00000257
_0824BE82:
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _0824BE82
	ldrh r0, [r4, #0xa]
	cmp r0, #0
	bne _0824BE9C
	ldr r0, _0824BEB4 @ =0x04000128
	ldrh r1, [r0]
	movs r2, #0x80
	orrs r1, r2
	strh r1, [r0]
_0824BE9C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0824BEA4: .4byte 0x00008001
_0824BEA8: .4byte 0x04000120
_0824BEAC: .4byte 0x0000494E
_0824BEB0: .4byte 0x00000257
_0824BEB4: .4byte 0x04000128

	thumb_func_start FUN_0824beb8
FUN_0824beb8: @ 0x0824BEB8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	mov r8, r1
	mov ip, r2
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	adds r1, r3, #0
	ldr r5, _0824BF00 @ =0x0000FFFF
	adds r7, r5, #0
	adds r2, r5, #0
	movs r0, #1
	ands r0, r3
	cmp r0, #0
	beq _0824BEDE
	ldr r7, _0824BF04 @ =0x00007F7E
_0824BEDE:
	movs r0, #2
	ands r0, r3
	cmp r0, #0
	beq _0824BEE8
	ldr r5, _0824BF08 @ =0x00007F7C
_0824BEE8:
	movs r0, #4
	ands r0, r3
	cmp r0, #0
	beq _0824BEF2
	ldr r2, _0824BF0C @ =0x00007F7A
_0824BEF2:
	cmp r1, #7
	bhi _0824BFAE
	movs r4, #0
	ldr r0, _0824BF10 @ =0x03005800
	ldr r1, [r0]
	adds r3, r0, #0
	b _0824BFA8
	.align 2, 0
_0824BF00: .4byte 0x0000FFFF
_0824BF04: .4byte 0x00007F7E
_0824BF08: .4byte 0x00007F7C
_0824BF0C: .4byte 0x00007F7A
_0824BF10: .4byte 0x03005800
_0824BF14:
	ldr r1, [r3]
	lsls r0, r4, #5
	adds r0, r1, r0
	ldrh r0, [r0, #0x18]
	cmp r0, r7
	beq _0824BF28
	cmp r0, r5
	beq _0824BF28
	cmp r0, r2
	bne _0824BFA2
_0824BF28:
	mov r0, ip
	adds r1, r4, #0
	bl FUN_0824c138
	adds r0, r4, #0
	mov r1, sp
	bl FUN_0824c0c4
	movs r5, #0
_0824BF3A:
	mov r0, sp
	adds r4, r0, r5
	adds r0, r4, #0
	bl FUN_0824c128
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r6, r0
	bne _0824BF7A
	adds r0, r4, #1
	bl FUN_0824c120
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	adds r0, r5, #2
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r4, #7
	bne _0824BF68
	movs r0, #0x11
	subs r0, r0, r5
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_0824BF68:
	mov r1, sp
	adds r0, r1, r5
	mov r1, r8
	adds r2, r4, #0
	bl FUN_0824c0f8
	lsls r0, r4, #0x18
	asrs r0, r0, #0x18
	b _0824BFB2
_0824BF7A:
	adds r4, #1
	adds r0, r4, #0
	bl FUN_0824c120
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	beq _0824BF9C
	adds r0, r4, #0
	bl FUN_0824c120
	adds r1, r5, #2
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0xf
	bls _0824BF3A
_0824BF9C:
	movs r0, #2
	rsbs r0, r0, #0
	b _0824BFB2
_0824BFA2:
	adds r0, r4, #1
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
_0824BFA8:
	ldrb r1, [r1, #8]
	cmp r4, r1
	blo _0824BF14
_0824BFAE:
	movs r0, #1
	rsbs r0, r0, #0
_0824BFB2:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0824BFC0:
	.byte 0xF0, 0xB5, 0x4F, 0x46, 0x46, 0x46, 0xC0, 0xB4, 0x85, 0xB0, 0x15, 0x1C, 0x00, 0x04, 0x07, 0x0C
	.byte 0x09, 0x06, 0x09, 0x0E, 0x0A, 0x1C, 0x0B, 0x4E, 0xB0, 0x46, 0xB4, 0x46, 0x01, 0x20, 0x08, 0x40
	.byte 0x00, 0x28, 0x01, 0xD0, 0x08, 0x48, 0x80, 0x46, 0x02, 0x20, 0x08, 0x40, 0x00, 0x28, 0x00, 0xD0
	.byte 0x06, 0x4E, 0x04, 0x20, 0x08, 0x40, 0x00, 0x28, 0x01, 0xD0, 0x05, 0x48, 0x84, 0x46, 0x07, 0x2A
	.byte 0x0A, 0xD9, 0x55, 0xE0, 0xFF, 0xFF, 0x00, 0x00, 0x7E, 0x7F, 0x00, 0x00, 0x7C, 0x7F, 0x00, 0x00
	.byte 0x7A, 0x7F, 0x00, 0x00, 0x30, 0x1C, 0x4D, 0xE0, 0x00, 0x23, 0x10, 0x48, 0x01, 0x68, 0x81, 0x46
	.byte 0x09, 0x7A, 0x8B, 0x42, 0x44, 0xD2, 0x48, 0x46, 0x02, 0x68, 0x59, 0x01, 0x50, 0x18, 0x00, 0x8B
	.byte 0x0C, 0x1C, 0x40, 0x45, 0x03, 0xD0, 0xB0, 0x42, 0x01, 0xD0, 0x60, 0x45, 0x32, 0xD1, 0x18, 0x1C
	.byte 0x69, 0x46, 0x00, 0xF0, 0x3F, 0xF8, 0x05, 0x48, 0x00, 0x68, 0x01, 0x19, 0x88, 0x7D, 0xFF, 0x28
	.byte 0x06, 0xD1, 0x88, 0x8A, 0x28, 0x80, 0x03, 0x26, 0x76, 0x42, 0x05, 0xE0, 0x00, 0x58, 0x00, 0x03
	.byte 0x88, 0x8A, 0x28, 0x80, 0x04, 0x26, 0x76, 0x42, 0x00, 0x25, 0x68, 0x46, 0x44, 0x19, 0x20, 0x1C
	.byte 0x00, 0xF0, 0x5A, 0xF8, 0x00, 0x04, 0x00, 0x0C, 0x87, 0x42, 0xCB, 0xD0, 0x01, 0x34, 0x20, 0x1C
	.byte 0x00, 0xF0, 0x4E, 0xF8, 0x00, 0x06, 0x00, 0x0E, 0x07, 0x28, 0x08, 0xD0, 0x20, 0x1C, 0x00, 0xF0
	.byte 0x47, 0xF8, 0xA9, 0x1C, 0x40, 0x18, 0x00, 0x06, 0x05, 0x0E, 0x0F, 0x2D, 0xE5, 0xD9, 0x02, 0x20
	.byte 0x40, 0x42, 0x07, 0xE0, 0x58, 0x1C, 0x00, 0x06, 0x03, 0x0E, 0x12, 0x7A, 0x93, 0x42, 0xBA, 0xD3
	.byte 0x01, 0x20, 0x40, 0x42, 0x05, 0xB0, 0x18, 0xBC, 0x98, 0x46, 0xA1, 0x46, 0xF0, 0xBC, 0x02, 0xBC
	.byte 0x08, 0x47, 0x00, 0x00

	thumb_func_start FUN_0824c0c4
FUN_0824c0c4: @ 0x0824C0C4
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	lsls r4, r4, #0x18
	ldr r6, _0824C0F4 @ =0x03005800
	lsrs r4, r4, #0x13
	adds r4, #0x14
	ldr r0, [r6]
	adds r0, r0, r4
	adds r0, #6
	movs r2, #0xd
	bl FUN_0824c0f8
	ldr r0, [r6]
	adds r0, r0, r4
	adds r0, #0x15
	adds r5, #0xd
	adds r1, r5, #0
	movs r2, #4
	bl FUN_0824c0f8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0824C0F4: .4byte 0x03005800

	thumb_func_start FUN_0824c0f8
FUN_0824c0f8: @ 0x0824C0F8
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r3, #0
	cmp r3, r2
	bhs _0824C11A
_0824C108:
	adds r1, r4, r3
	adds r0, r5, r3
	ldrb r0, [r0]
	strb r0, [r1]
	adds r0, r3, #1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, r2
	blo _0824C108
_0824C11A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0824c120
FUN_0824c120: @ 0x0824C120
	ldrb r0, [r0]
	lsrs r0, r0, #5
	bx lr
	.align 2, 0

	thumb_func_start FUN_0824c128
FUN_0824c128: @ 0x0824C128
	ldrb r2, [r0, #1]
	movs r1, #0x1f
	ands r1, r2
	lsls r1, r1, #8
	ldrb r0, [r0]
	orrs r0, r1
	bx lr
	.align 2, 0

	thumb_func_start FUN_0824c138
FUN_0824c138: @ 0x0824C138
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	lsls r1, r1, #0x18
	ldr r0, _0824C1B0 @ =0x03005800
	lsrs r1, r1, #0x13
	adds r1, #0x14
	ldr r0, [r0]
	adds r0, r0, r1
	adds r0, #0x19
	mov r1, sp
	movs r2, #4
	bl FUN_0824c0f8
	mov r0, sp
	ldrb r2, [r0, #3]
	lsls r1, r2, #0x18
	lsrs r0, r1, #0x1d
	adds r0, #3
	strb r0, [r4]
	lsrs r1, r1, #0x19
	movs r0, #0xf
	ands r1, r0
	strb r1, [r4, #1]
	movs r3, #1
	adds r0, r3, #0
	ands r0, r2
	lsls r0, r0, #4
	mov r1, sp
	ldrb r2, [r1, #2]
	lsrs r1, r2, #4
	orrs r0, r1
	strb r0, [r4, #2]
	movs r0, #0xf
	ands r0, r2
	lsls r0, r0, #1
	mov r1, sp
	ldrb r5, [r1, #1]
	lsls r1, r5, #0x18
	lsrs r2, r1, #0x1f
	orrs r0, r2
	strb r0, [r4, #3]
	lsrs r1, r1, #0x19
	movs r0, #0x3f
	ands r1, r0
	strb r1, [r4, #4]
	ands r3, r5
	lsls r3, r3, #5
	mov r0, sp
	ldrb r1, [r0]
	lsrs r0, r1, #3
	orrs r3, r0
	strb r3, [r4, #5]
	movs r0, #7
	ands r0, r1
	strb r0, [r4, #6]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0824C1B0: .4byte 0x03005800
