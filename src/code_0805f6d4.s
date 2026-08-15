	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0805f6d4
FUN_0805f6d4: @ 0x0805F6D4
	ldr r1, _0805F6DC @ =0x03000130
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0805F6DC: .4byte 0x03000130

	thumb_func_start FUN_0805f6e0
FUN_0805f6e0: @ 0x0805F6E0
	movs r2, #1
	lsls r2, r1
	ldr r1, [r0, #0x18]
	orrs r1, r2
	str r1, [r0, #0x18]
	bx lr

	thumb_func_start FUN_0805f6ec
FUN_0805f6ec: @ 0x0805F6EC
	movs r2, #1
	lsls r2, r1
	ldr r1, [r0, #0x18]
	bics r1, r2
	str r1, [r0, #0x18]
	bx lr

	thumb_func_start FUN_0805f6f8
FUN_0805f6f8: @ 0x0805F6F8
	movs r2, #1
	lsls r2, r1
	ldr r0, [r0, #0x18]
	ands r0, r2
	bx lr
	.align 2, 0

	thumb_func_start FUN_0805f704
FUN_0805f704: @ 0x0805F704
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r7, r1, #0
	adds r5, r6, #0
	adds r5, #0x20
	movs r4, #0
_0805F710:
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0805f6f8
	cmp r0, #0
	beq _0805F726
	ldr r0, [r5]
	cmp r0, r7
	bne _0805F726
	adds r0, r4, #0
	b _0805F732
_0805F726:
	adds r4, #1
	adds r5, #0xb4
	cmp r4, #3
	ble _0805F710
	movs r0, #1
	rsbs r0, r0, #0
_0805F732:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805f738
FUN_0805f738: @ 0x0805F738
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r4, #0
_0805F740:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0805f6f8
	cmp r0, #0
	beq _0805F75E
	adds r4, #1
	cmp r4, #3
	ble _0805F740
	adds r1, r5, #0
	adds r1, #0x20
	movs r4, #0
_0805F758:
	ldrb r0, [r1, #4]
	cmp r0, r6
	bgt _0805F762
_0805F75E:
	adds r0, r4, #0
	b _0805F76E
_0805F762:
	adds r4, #1
	adds r1, #0xb4
	cmp r4, #3
	ble _0805F758
	movs r0, #1
	rsbs r0, r0, #0
_0805F76E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805f774
FUN_0805f774: @ 0x0805F774
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r7, r0, #0
	adds r6, r1, #0
	adds r4, r2, #0
	mov r8, r3
	ldr r0, [sp, #0x30]
	mov sl, r0
	movs r1, #0
	mov sb, r1
	ldrb r2, [r6, #7]
	cmp sb, r2
	bge _0805F7AC
	adds r5, r6, #0
	adds r5, #0x14
_0805F79A:
	adds r0, r5, #0
	bl FUN_0822dabc
	adds r5, #0x28
	movs r3, #1
	add sb, r3
	ldrb r0, [r6, #7]
	cmp sb, r0
	blt _0805F79A
_0805F7AC:
	movs r0, #0
	strb r0, [r6, #7]
	mov r1, sl
	ldrh r0, [r1, #2]
	strh r0, [r6, #8]
	ldrh r0, [r1, #2]
	adds r0, #6
	strh r0, [r6, #0xa]
	ldr r1, _0805F8C4 @ =0x0000270F
	adds r0, r6, #0
	adds r0, #0x8c
	movs r2, #0x64
	adds r2, r2, r6
	mov sb, r2
	movs r3, #0x3c
	adds r3, r3, r6
	mov sl, r3
	adds r2, r6, #0
	adds r2, #0x14
	str r2, [sp, #8]
	cmp r4, r1
	bls _0805F7E0
	ldr r2, _0805F8C8 @ =0xFFFFD8F0
_0805F7DA:
	adds r4, r4, r2
	cmp r4, r1
	bhi _0805F7DA
_0805F7E0:
	movs r5, #0
	ldr r1, _0805F8CC @ =0x000003E7
	cmp r4, r1
	bls _0805F7F2
	ldr r2, _0805F8D0 @ =0xFFFFFC18
_0805F7EA:
	adds r5, #1
	adds r4, r4, r2
	cmp r4, r1
	bhi _0805F7EA
_0805F7F2:
	ldr r1, [r7, #0x1c]
	mov r3, r8
	adds r2, r3, r5
	bl FUN_0822dafc
	cmp r5, #0
	ble _0805F804
	movs r0, #4
	strb r0, [r6, #7]
_0805F804:
	movs r5, #0
	cmp r4, #0x63
	bls _0805F812
_0805F80A:
	adds r5, #1
	subs r4, #0x64
	cmp r4, #0x63
	bhi _0805F80A
_0805F812:
	ldr r1, [r7, #0x1c]
	mov r0, r8
	adds r2, r0, r5
	mov r0, sb
	bl FUN_0822dafc
	ldrb r0, [r6, #7]
	cmp r0, #0
	bne _0805F82C
	cmp r5, #0
	ble _0805F82C
	movs r0, #3
	strb r0, [r6, #7]
_0805F82C:
	movs r5, #0
	cmp r4, #9
	bls _0805F83A
_0805F832:
	adds r5, #1
	subs r4, #0xa
	cmp r4, #9
	bhi _0805F832
_0805F83A:
	ldr r1, [r7, #0x1c]
	mov r3, r8
	adds r2, r3, r5
	mov r0, sl
	bl FUN_0822dafc
	ldrb r0, [r6, #7]
	cmp r0, #0
	bne _0805F854
	cmp r5, #0
	ble _0805F854
	movs r0, #2
	strb r0, [r6, #7]
_0805F854:
	movs r5, #0
	ldr r1, [r7, #0x1c]
	cmp r4, #0
	beq _0805F864
_0805F85C:
	adds r5, #1
	subs r4, #1
	cmp r4, #0
	bne _0805F85C
_0805F864:
	ldr r0, [sp, #8]
	mov r7, r8
	adds r2, r7, r5
	bl FUN_0822dafc
	ldrb r1, [r6, #7]
	cmp r1, #0
	bne _0805F878
	movs r1, #1
	strb r1, [r6, #7]
_0805F878:
	ldr r1, [sp, #8]
	mov r8, r1
	movs r2, #0
	mov sb, r2
	ldrb r3, [r6, #7]
	cmp sb, r3
	blt _0805F888
	b _0805F996
_0805F888:
	ldr r7, _0805F8D4 @ =0x030047C8
	mov sl, r7
	movs r0, #0
	str r0, [sp, #0xc]
_0805F890:
	ldrb r0, [r6, #5]
	lsls r0, r0, #4
	mov r2, sb
	lsls r1, r2, #5
	adds r5, r0, r1
	cmp r5, #0x80
	ble _0805F8A0
	movs r5, #0x80
_0805F8A0:
	mov r4, sp
	adds r7, r6, #0
	adds r7, #0xc
	ldrh r0, [r6, #0xc]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0805F8D8
	asrs r0, r0, #8
	b _0805F8DE
	.align 2, 0
_0805F8C4: .4byte 0x0000270F
_0805F8C8: .4byte 0xFFFFD8F0
_0805F8CC: .4byte 0x000003E7
_0805F8D0: .4byte 0xFFFFFC18
_0805F8D4: .4byte 0x030047C8
_0805F8D8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0805F8DE:
	strh r0, [r4]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0805F8F0
	asrs r0, r0, #8
	b _0805F8F6
_0805F8F0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0805F8F6:
	adds r3, r0, #0
	movs r0, #2
	ldrsh r1, [r7, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0805F90A
	asrs r0, r0, #8
	b _0805F910
_0805F90A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0805F910:
	subs r2, r3, r0
	adds r3, r3, r0
	ldrh r0, [r4]
	mov r7, sl
	ldrh r1, [r7]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r4]
	ldrh r0, [r7, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r4, #2]
	ldrh r0, [r7, #4]
	subs r3, r3, r0
	strh r3, [r4, #4]
	mov r0, sp
	ldrh r1, [r0]
	ldr r0, [sp, #0xc]
	subs r1, r1, r0
	ldr r2, _0805F960 @ =0x085ABA88
	ldrb r0, [r6, #7]
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	subs r1, r1, r0
	mov r2, r8
	strh r1, [r2, #0x18]
	ldr r1, _0805F964 @ =0x085B0A08
	movs r0, #0xff
	ands r5, r0
	lsls r0, r5, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	lsls r0, r0, #4
	cmp r0, #0
	blt _0805F968
	asrs r1, r0, #0xc
	b _0805F96E
	.align 2, 0
_0805F960: .4byte 0x085ABA88
_0805F964: .4byte 0x085B0A08
_0805F968:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805F96E:
	mov r0, sp
	ldrh r0, [r0, #2]
	subs r0, r0, r1
	mov r7, r8
	strh r0, [r7, #0x1a]
	mov r0, r8
	movs r1, #0
	bl FUN_0822da50
	ldr r1, [sp, #0xc]
	adds r1, #5
	str r1, [sp, #0xc]
	movs r2, #1
	add sb, r2
	movs r3, #0x28
	add r8, r3
	ldrb r7, [r6, #7]
	cmp sb, r7
	bge _0805F996
	b _0805F890
_0805F996:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805f9a8
FUN_0805f9a8: @ 0x0805F9A8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov r8, r0
	mov sl, r1
	mov sb, r2
	mov ip, r3
	ldr r3, [sp, #0x2c]
	ldr r2, [sp, #0x30]
	ldr r1, [sp, #0x34]
	movs r0, #0xb4
	mov r4, sl
	muls r4, r0, r4
	adds r0, r4, #0
	adds r0, #0x20
	mov r4, r8
	adds r5, r4, r0
	str r1, [r5]
	movs r0, #0
	add r1, sp, #0x38
	ldrb r1, [r1]
	strb r1, [r5, #4]
	strb r0, [r5, #5]
	strb r0, [r5, #6]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r5, #0xc]
	str r1, [r5, #0x10]
	ldrh r1, [r2]
	ldrh r3, [r5, #0xc]
	adds r1, r1, r3
	strh r1, [r5, #0xc]
	ldrh r0, [r2, #2]
	ldrh r4, [r5, #0xe]
	adds r0, r0, r4
	strh r0, [r5, #0xe]
	ldrh r0, [r2, #4]
	ldrh r2, [r5, #0x10]
	adds r0, r0, r2
	strh r0, [r5, #0x10]
	add r6, sp, #4
	adds r7, r5, #0
	adds r7, #0xc
	lsls r1, r1, #0x10
	asrs r3, r1, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0805FA1E
	asrs r0, r0, #8
	b _0805FA24
_0805FA1E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0805FA24:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0805FA36
	asrs r0, r0, #8
	b _0805FA3C
_0805FA36:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0805FA3C:
	adds r4, r0, #0
	movs r3, #2
	ldrsh r1, [r7, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0805FA50
	asrs r0, r0, #8
	b _0805FA56
_0805FA50:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0805FA56:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0805FA98 @ =0x030047C8
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
	ldr r4, [sp, #0x38]
	cmp r4, #0
	beq _0805FA7E
	cmp r4, #2
	bne _0805FA9C
_0805FA7E:
	movs r3, #0x2a
	mov r0, ip
	cmp r0, #0
	bne _0805FA88
	movs r3, #0x20
_0805FA88:
	add r1, sp, #4
	str r1, [sp]
	mov r0, r8
	adds r1, r5, #0
	mov r2, sb
	bl FUN_0805f774
	b _0805FAB4
	.align 2, 0
_0805FA98: .4byte 0x030047C8
_0805FA9C:
	movs r3, #0x3e
	mov r2, ip
	cmp r2, #0
	bne _0805FAA6
	movs r3, #0x34
_0805FAA6:
	add r4, sp, #4
	str r4, [sp]
	mov r0, r8
	adds r1, r5, #0
	mov r2, sb
	bl FUN_0805f774
_0805FAB4:
	mov r0, r8
	mov r1, sl
	bl FUN_0805f6e0
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805facc
FUN_0805facc: @ 0x0805FACC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	mov r8, r1
	movs r0, #0xb4
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, #0x20
	adds r6, r7, r0
	movs r5, #0
	ldrb r0, [r6, #7]
	cmp r5, r0
	bge _0805FAFE
	adds r4, r6, #0
	adds r4, #0x14
_0805FAEE:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x28
	adds r5, #1
	ldrb r1, [r6, #7]
	cmp r5, r1
	blt _0805FAEE
_0805FAFE:
	movs r0, #0
	strb r0, [r6, #7]
	adds r0, r7, #0
	mov r1, r8
	bl FUN_0805f6ec
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0805fb14
FUN_0805fb14: @ 0x0805FB14
	ldrb r1, [r0, #6]
	adds r1, #1
	movs r2, #0
	strb r1, [r0, #6]
	strb r2, [r0, #5]
	bx lr

	thumb_func_start FUN_0805fb20
FUN_0805fb20: @ 0x0805FB20
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r1, #0
	mov r6, sp
	adds r7, r5, #0
	adds r7, #0xc
	ldrh r0, [r5, #0xc]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0805FB4C
	asrs r0, r0, #8
	b _0805FB52
_0805FB4C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0805FB52:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0805FB64
	asrs r0, r0, #8
	b _0805FB6A
_0805FB64:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0805FB6A:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r7, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0805FB7E
	asrs r0, r0, #8
	b _0805FB84
_0805FB7E:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0805FB84:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0805FBF0 @ =0x030047C8
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
	adds r3, r5, #0
	adds r3, #0x14
	movs r4, #0
	ldrb r1, [r5, #7]
	cmp r4, r1
	bge _0805FC14
	mov r6, sp
	ldr r0, _0805FBF4 @ =0x085ABA88
	mov r8, r0
	ldr r1, _0805FBF8 @ =0x085B0A08
	mov ip, r1
	movs r7, #0
_0805FBBA:
	ldrb r0, [r5, #5]
	lsls r0, r0, #4
	lsls r1, r4, #5
	adds r2, r0, r1
	cmp r2, #0x60
	ble _0805FBC8
	movs r2, #0x60
_0805FBC8:
	ldrh r1, [r6]
	subs r1, r1, r7
	ldrb r0, [r5, #7]
	lsls r0, r0, #2
	add r0, r8
	ldr r0, [r0]
	subs r1, r1, r0
	strh r1, [r3, #0x18]
	movs r0, #0xff
	ands r2, r0
	lsls r0, r2, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	cmp r0, #0
	blt _0805FBFC
	asrs r1, r0, #0xc
	b _0805FC02
	.align 2, 0
_0805FBF0: .4byte 0x030047C8
_0805FBF4: .4byte 0x085ABA88
_0805FBF8: .4byte 0x085B0A08
_0805FBFC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805FC02:
	ldrh r0, [r6, #2]
	subs r0, r0, r1
	strh r0, [r3, #0x1a]
	adds r7, #5
	adds r4, #1
	adds r3, #0x28
	ldrb r0, [r5, #7]
	cmp r4, r0
	blt _0805FBBA
_0805FC14:
	ldrb r0, [r5, #5]
	adds r0, #1
	strb r0, [r5, #5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x13
	bls _0805FC28
	adds r0, r5, #0
	bl FUN_0805fb14
_0805FC28:
	movs r0, #0
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805fc38
FUN_0805fc38: @ 0x0805FC38
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov sb, r0
	mov ip, r1
	mov r8, r2
	mov r5, sp
	mov r6, ip
	adds r6, #0xc
	ldrh r0, [r1, #0xc]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0805FC6A
	asrs r0, r0, #8
	b _0805FC70
_0805FC6A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0805FC70:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _0805FC82
	asrs r0, r0, #8
	b _0805FC88
_0805FC82:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0805FC88:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r6, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _0805FC9C
	asrs r0, r0, #8
	b _0805FCA2
_0805FC9C:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_0805FCA2:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _0805FCF0 @ =0x030047C8
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
	mov r2, ip
	adds r2, #0x14
	movs r4, #0
	mov r1, ip
	ldrb r0, [r1, #7]
	cmp r4, r0
	bge _0805FD16
	mov r5, sp
	ldr r7, _0805FCF4 @ =0x085ABA88
	ldr r6, _0805FCF8 @ =0x085B0AC8
	ldrh r3, [r5]
_0805FCD6:
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r0, [r0]
	subs r0, r3, r0
	strh r0, [r2, #0x18]
	movs r1, #0
	ldrsh r0, [r6, r1]
	lsls r0, r0, #4
	cmp r0, #0
	blt _0805FCFC
	asrs r1, r0, #0xc
	b _0805FD02
	.align 2, 0
_0805FCF0: .4byte 0x030047C8
_0805FCF4: .4byte 0x085ABA88
_0805FCF8: .4byte 0x085B0AC8
_0805FCFC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805FD02:
	ldrh r0, [r5, #2]
	subs r0, r0, r1
	strh r0, [r2, #0x1a]
	subs r3, #5
	adds r4, #1
	adds r2, #0x28
	mov r1, ip
	ldrb r0, [r1, #7]
	cmp r4, r0
	blt _0805FCD6
_0805FD16:
	mov r1, ip
	ldrb r0, [r1, #5]
	adds r0, #1
	strb r0, [r1, #5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #9
	bls _0805FD2E
	mov r0, sb
	mov r1, r8
	bl FUN_0805facc
_0805FD2E:
	movs r0, #0
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0805fd40
FUN_0805fd40: @ 0x0805FD40
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x20
	movs r5, #0
	ldr r7, _0805FD7C @ =0x085ABA9C
_0805FD4C:
	adds r0, r6, #0
	adds r1, r5, #0
	bl FUN_0805f6f8
	cmp r0, #0
	beq _0805FD6A
	ldrb r0, [r4, #6]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
_0805FD6A:
	adds r5, #1
	adds r4, #0xb4
	cmp r5, #3
	ble _0805FD4C
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805FD7C: .4byte 0x085ABA9C

	thumb_func_start FUN_0805fd80
FUN_0805fd80: @ 0x0805FD80
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r4, #0
_0805FD86:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0805facc
	adds r4, #1
	cmp r4, #3
	ble _0805FD86
	ldr r1, _0805FDA0 @ =0x03000130
	movs r0, #0
	str r0, [r1]
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0805FDA0: .4byte 0x03000130

	thumb_func_start FUN_0805fda4
FUN_0805fda4: @ 0x0805FDA4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	ldr r0, _0805FE24 @ =0x03000130
	str r7, [r0]
	ldr r0, _0805FE28 @ =0x00001C1C
	bl GetParticleGroup
	str r0, [r7, #0x1c]
	movs r0, #0
	str r0, [r7, #0x18]
	adds r5, r7, #0
	adds r5, #0x20
	movs r1, #4
	rsbs r1, r1, #0
	mov sl, r1
_0805FDCA:
	adds r4, r5, #0
	adds r4, #0x14
	adds r0, #1
	mov sb, r0
	movs r0, #0xb4
	adds r0, r0, r5
	mov r8, r0
	movs r6, #3
_0805FDDA:
	ldr r1, [r7, #0x1c]
	adds r0, r4, #0
	ldr r2, _0805FE2C @ =0x00010010
	bl FUN_0822da70
	adds r0, r4, #0
	mov r1, sl
	mov r2, sl
	bl FUN_0822dad4
	ldr r1, [r7, #0x1c]
	adds r0, r4, #0
	movs r2, #0x20
	bl FUN_0822dafc
	movs r0, #1
	strb r0, [r4, #0xf]
	subs r6, #1
	adds r4, #0x28
	cmp r6, #0
	bge _0805FDDA
	movs r0, #3
	strb r0, [r5, #4]
	movs r1, #0
	strb r1, [r5, #7]
	mov r0, sb
	mov r5, r8
	cmp r0, #3
	ble _0805FDCA
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805FE24: .4byte 0x03000130
_0805FE28: .4byte 0x00001C1C
_0805FE2C: .4byte 0x00010010

	thumb_func_start FUN_0805fe30
FUN_0805fe30: @ 0x0805FE30
	push {r4, lr}
	ldr r0, _0805FE68 @ =0x03000130
	ldr r0, [r0]
	cmp r0, #0
	bne _0805FE76
	movs r1, #0xbc
	lsls r1, r1, #2
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0805FE74
	ldr r1, _0805FE6C @ =FUN_0805fd40
	ldr r2, _0805FE70 @ =FUN_0805fd80
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_0805fda4
	cmp r0, #0
	bge _0805FE74
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0805FE76
	.align 2, 0
_0805FE68: .4byte 0x03000130
_0805FE6C: .4byte FUN_0805fd40
_0805FE70: .4byte FUN_0805fd80
_0805FE74:
	adds r0, r4, #0
_0805FE76:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0805fe7c
FUN_0805fe7c: @ 0x0805FE7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r6, r0, #0
	mov sb, r1
	mov sl, r2
	mov r8, r3
	ldr r7, [sp, #0x34]
	ldr r0, _0805FECC @ =0x03000130
	ldr r4, [r0]
	cmp r4, #0
	bne _0805FEA4
	bl FUN_0805fe30
	adds r4, r0, #0
	cmp r4, #0
	beq _0805FEC6
_0805FEA4:
	lsls r5, r6, #0x10
	ldrh r0, [r6, #4]
	orrs r5, r0
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0805f704
	adds r1, r0, #0
	cmp r1, #0
	bge _0805FED0
	adds r0, r4, #0
	adds r1, r7, #0
	bl FUN_0805f738
	adds r1, r0, #0
	cmp r1, #0
	bge _0805FEDE
_0805FEC6:
	movs r0, #1
	rsbs r0, r0, #0
	b _0805FEF4
	.align 2, 0
_0805FECC: .4byte 0x03000130
_0805FED0:
	movs r0, #0xb4
	muls r0, r1, r0
	adds r0, r4, r0
	adds r0, #0x24
	ldrb r0, [r0]
	cmp r7, r0
	blt _0805FEC6
_0805FEDE:
	mov r0, r8
	str r0, [sp]
	ldr r0, [sp, #0x30]
	str r0, [sp, #4]
	str r5, [sp, #8]
	str r7, [sp, #0xc]
	adds r0, r4, #0
	mov r2, sb
	mov r3, sl
	bl FUN_0805f9a8
_0805FEF4:
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

