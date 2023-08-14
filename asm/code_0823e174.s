	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0823e1b0
FUN_0823e1b0: @ 0x0823E1B0
	push {r4, lr}
	ldr r0, _0823E1D4 @ =0x030047E0
	ldrb r2, [r0, #4]
	ldrb r1, [r0, #0xa]
	adds r4, r0, #0
	cmp r2, r1
	bhs _0823E1DE
	ldrb r0, [r4, #0xc]
	cmp r0, r1
	bhs _0823E1D8
	cmp r2, r0
	blo _0823E26E
	cmp r2, r0
	bne _0823E256
	ldrb r0, [r4, #5]
	movs r3, #0
	ldrb r1, [r4, #0xd]
	b _0823E24A
	.align 2, 0
_0823E1D4: .4byte 0x030047E0
_0823E1D8:
	cmp r0, r1
	bne _0823E256
	b _0823E244
_0823E1DE:
	cmp r2, r1
	bne _0823E1FE
	ldrb r0, [r4, #0xc]
	cmp r0, r1
	bne _0823E1F2
	ldrb r1, [r4, #0xd]
	ldrb r0, [r4, #0xb]
	cmp r1, r0
	blo _0823E214
	b _0823E222
_0823E1F2:
	ldrb r0, [r4, #5]
	movs r3, #1
	ldrb r1, [r4, #0xb]
	cmp r0, r1
	bhs _0823E252
	b _0823E256
_0823E1FE:
	ldrb r0, [r4, #0xc]
	cmp r2, r0
	blo _0823E26E
	cmp r2, r0
	bne _0823E23C
	cmp r0, r1
	bne _0823E234
	ldrb r1, [r4, #0xd]
	ldrb r0, [r4, #0xb]
	cmp r1, r0
	bhs _0823E222
_0823E214:
	ldrb r2, [r4, #5]
	movs r3, #1
	cmp r2, r1
	blo _0823E26E
	cmp r2, r0
	bhs _0823E252
	b _0823E256
_0823E222:
	cmp r0, r1
	bhs _0823E256
	ldrb r2, [r4, #5]
	movs r3, #0
	cmp r2, r0
	blo _0823E256
	cmp r2, r1
	bhs _0823E252
	b _0823E26E
_0823E234:
	ldrb r0, [r4, #5]
	movs r3, #0
	ldrb r1, [r4, #0xd]
	b _0823E24A
_0823E23C:
	cmp r0, r1
	blo _0823E26E
	cmp r0, r1
	bne _0823E250
_0823E244:
	ldrb r0, [r4, #0xd]
	movs r3, #0
	ldrb r1, [r4, #0xb]
_0823E24A:
	cmp r0, r1
	bhs _0823E252
	b _0823E26E
_0823E250:
	movs r3, #0
_0823E252:
	cmp r3, #0
	bne _0823E26E
_0823E256:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0823E260
	movs r0, #0
	b _0823E284
_0823E260:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	bne _0823E26A
	movs r0, #4
	b _0823E284
_0823E26A:
	movs r0, #5
	b _0823E284
_0823E26E:
	ldrb r0, [r4, #0x12]
	cmp r0, #0
	bne _0823E278
	movs r0, #1
	b _0823E284
_0823E278:
	ldrb r0, [r4, #0x10]
	cmp r0, #0
	beq _0823E282
	movs r0, #2
	b _0823E284
_0823E282:
	movs r0, #3
_0823E284:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823e28c
FUN_0823e28c: @ 0x0823E28C
	ldr r0, _0823E294 @ =0x030047E0
	ldrb r0, [r0, #9]
	bx lr
	.align 2, 0
_0823E294: .4byte 0x030047E0

	thumb_func_start FUN_0823e298
FUN_0823e298: @ 0x0823E298
	push {r4, r5, lr}
	sub sp, #0x14
	add r1, sp, #4
	add r2, sp, #8
	ldr r5, _0823E314 @ =0x030047E0
	ldr r3, [r5]
	mov r0, sp
	bl FUN_0823db08
	add r4, sp, #0xc
	adds r0, r4, #0
	bl FUN_0823167c
	ldr r2, [sp]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	ldr r2, [sp, #4]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	ldr r2, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	ldrb r2, [r5, #4]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	ldrb r2, [r5, #5]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	adds r0, r4, #0
	bl FUN_0823167c
	ldrb r2, [r5, #6]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0823206c
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0823E314: .4byte 0x030047E0

	thumb_func_start FUN_0823e318
FUN_0823e318: @ 0x0823E318
	push {lr}
	sub sp, #8
	mov r0, sp
	bl FUN_0823167c
	ldr r0, _0823E334 @ =0x030047E0
	ldrb r2, [r0, #8]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	add sp, #8
	pop {r0}
	bx r0
	.align 2, 0
_0823E334: .4byte 0x030047E0

	thumb_func_start FUN_0823e338
FUN_0823e338: @ 0x0823E338
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x10
	bl fetch_082316e4
	mov sb, r0
	bl fetch_082316e4
	mov r8, r0
	bl fetch_082316e4
	adds r6, r0, #0
	bl fetch_082316e4
	adds r5, r0, #0
	bl fetch_082316e4
	adds r4, r0, #0
	bl fetch_082316e4
	str r4, [sp]
	str r0, [sp, #4]
	mov r0, sb
	mov r1, r8
	adds r2, r6, #0
	adds r3, r5, #0
	bl FUN_0823d9ec
	adds r4, r0, #0
	add r0, sp, #8
	bl FUN_0823167c
	add r0, sp, #8
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823206c
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0823e394
FUN_0823e394: @ 0x0823E394
	push {r4, lr}
	sub sp, #8
	mov r0, sp
	bl FUN_0823167c
	ldr r4, _0823E3E4 @ =0x030047E0
	ldrb r2, [r4, #0xa]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	ldrb r2, [r4, #0xb]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	ldrb r2, [r4, #0x12]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	ldrb r2, [r4, #0x13]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823E3E4: .4byte 0x030047E0

	thumb_func_start FUN_0823e3e8
FUN_0823e3e8: @ 0x0823E3E8
	push {r4, lr}
	sub sp, #8
	mov r0, sp
	bl FUN_0823167c
	ldr r4, _0823E438 @ =0x030047E0
	ldrb r2, [r4, #0xc]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	ldrb r2, [r4, #0xd]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	ldrb r2, [r4, #0x10]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	mov r0, sp
	bl FUN_0823167c
	ldrb r2, [r4, #0x11]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0823E438: .4byte 0x030047E0

	thumb_func_start FUN_0823e43c
FUN_0823e43c: @ 0x0823E43C
	push {r4, r5, lr}
	sub sp, #8
	ldr r4, _0823E460 @ =0x030047E0
	ldrb r5, [r4, #0xe]
	mov r0, sp
	bl FUN_0823167c
	ldrb r2, [r4, #0xe]
	mov r0, sp
	movs r1, #0
	bl FUN_0823206c
	adds r0, r5, #0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0823E460: .4byte 0x030047E0
_0823E464:
	.byte 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00, 0x70, 0x47, 0x00, 0x00

	thumb_func_start FUN_0823e470
FUN_0823e470: @ 0x0823E470
	push {lr}
	ldr r3, _0823E48C @ =0x030047E0
	lsls r2, r0, #2
	adds r2, r2, r0
	lsls r2, r2, #1
	adds r2, r2, r1
	strh r2, [r3, #0x14]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	cmp r2, #0x22
	bhi _0823E490
	movs r0, #0
	b _0823E4C2
	.align 2, 0
_0823E48C: .4byte 0x030047E0
_0823E490:
	cmp r2, #0x45
	bhi _0823E498
	movs r0, #1
	b _0823E4C2
_0823E498:
	cmp r2, #0x68
	bhi _0823E4A0
	movs r0, #2
	b _0823E4C2
_0823E4A0:
	cmp r2, #0x95
	bhi _0823E4A8
	movs r0, #3
	b _0823E4C2
_0823E4A8:
	cmp r2, #0x9f
	bhi _0823E4B0
	movs r0, #4
	b _0823E4C2
_0823E4B0:
	cmp r2, #0xd1
	bhi _0823E4B8
	movs r0, #5
	b _0823E4C2
_0823E4B8:
	cmp r2, #0xf4
	bhi _0823E4C0
	movs r0, #6
	b _0823E4C2
_0823E4C0:
	movs r0, #7
_0823E4C2:
	strb r0, [r3, #0x16]
	pop {r0}
	bx r0

	thumb_func_start FUN_0823e4c8
FUN_0823e4c8: @ 0x0823E4C8
	ldr r0, _0823E4D0 @ =0x030047E0
	ldrh r0, [r0, #0x14]
	bx lr
	.align 2, 0
_0823E4D0: .4byte 0x030047E0

	thumb_func_start FUN_0823e4d4
FUN_0823e4d4: @ 0x0823E4D4
	ldr r0, _0823E4DC @ =0x030047E0
	ldrb r0, [r0, #0x16]
	bx lr
	.align 2, 0
_0823E4DC: .4byte 0x030047E0
_0823E4E0:
	.byte 0x01, 0x48, 0x80, 0x7D, 0x70, 0x47, 0x00, 0x00, 0xE0, 0x47, 0x00, 0x03

	thumb_func_start FUN_0823e4ec
FUN_0823e4ec: @ 0x0823E4EC
	push {r4, r5, r6, lr}
	sub sp, #0xc
	movs r5, #0
	movs r4, #0
	movs r6, #1
	rsbs r6, r6, #0
	b _0823E502
_0823E4FA:
	movs r0, #0xc8
	bl FUN_0823d8f4
	adds r4, #1
_0823E502:
	cmp r4, #4
	bgt _0823E510
	bl FUN_0823e828
	adds r5, r0, #0
	cmp r5, r6
	beq _0823E4FA
_0823E510:
	cmp r5, #1
	bne _0823E54C
	bl FUN_0823e768
	cmp r0, #1
	bne _0823E528
	ldr r1, _0823E524 @ =0x030047E0
	movs r0, #0
	strb r0, [r1, #9]
	b _0823E566
	.align 2, 0
_0823E524: .4byte 0x030047E0
_0823E528:
	ldr r0, _0823E544 @ =0x000007D4
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r5, [sp, #8]
	movs r1, #7
	movs r2, #0x16
	movs r3, #0xc
	bl FUN_0823e038
	ldr r0, _0823E548 @ =0x030047E0
	strb r5, [r0, #9]
	b _0823E566
	.align 2, 0
_0823E544: .4byte 0x000007D4
_0823E548: .4byte 0x030047E0
_0823E54C:
	ldr r0, _0823E570 @ =0x000007D4
	movs r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	movs r4, #1
	str r4, [sp, #8]
	movs r1, #7
	movs r2, #0x16
	movs r3, #0xc
	bl FUN_0823e038
	ldr r0, _0823E574 @ =0x030047E0
	strb r4, [r0, #9]
_0823E566:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0823E570: .4byte 0x000007D4
_0823E574: .4byte 0x030047E0

	thumb_func_start FUN_0823e578
FUN_0823e578: @ 0x0823E578
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	mov sb, r1
	mov sl, r2
	adds r5, r3, #0
	ldr r6, [sp, #0x20]
	adds r0, #0x30
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl FUN_0823dc40
	ldr r4, _0823E5F8 @ =0x03004810
	movs r7, #0
	strb r0, [r4]
	mov r1, sb
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	bl FUN_0823dc40
	strb r0, [r4, #1]
	mov r1, sl
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	bl FUN_0823dc40
	strb r0, [r4, #2]
	mov r0, r8
	mov r1, sb
	mov r2, sl
	bl FUN_0823daa4
	strb r0, [r4, #3]
	lsls r5, r5, #0x18
	lsrs r5, r5, #0x18
	adds r0, r5, #0
	bl FUN_0823dc40
	strb r0, [r4, #4]
	lsls r6, r6, #0x18
	lsrs r6, r6, #0x18
	adds r0, r6, #0
	bl FUN_0823dc40
	strb r0, [r4, #5]
	ldr r1, [sp, #0x24]
	lsls r0, r1, #0x18
	lsrs r0, r0, #0x18
	bl FUN_0823dc40
	strb r0, [r4, #6]
	strb r7, [r4, #7]
	movs r6, #0
	bl FUN_08241704
	ldr r0, _0823E5FC @ =0x04000208
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r5, _0823E600 @ =0x04000200
	b _0823E60C
	.align 2, 0
_0823E5F8: .4byte 0x03004810
_0823E5FC: .4byte 0x04000208
_0823E600: .4byte 0x04000200
_0823E604:
	movs r0, #0xc8
	bl FUN_0823d8f4
	adds r7, #1
_0823E60C:
	cmp r7, #4
	bgt _0823E638
	mov r1, r8
	mov r0, sb
	strh r1, [r0]
	ldrh r4, [r5]
	strh r1, [r5]
	bl FUN_0823d904
	ldr r0, _0823E64C @ =0x03004810
	bl FUN_0824c948
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	bl FUN_0823d910
	strh r4, [r5]
	movs r0, #1
	mov r1, sb
	strh r0, [r1]
	cmp r6, #1
	bne _0823E604
_0823E638:
	bl FUN_0824172c
	adds r0, r6, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823E64C: .4byte 0x03004810

	thumb_func_start FUN_0823e650
FUN_0823e650: @ 0x0823E650
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	bl FUN_08241704
	movs r7, #0
	ldr r0, _0823E66C @ =0x04000208
	mov sb, r0
	movs r1, #0
	mov r8, r1
	ldr r6, _0823E670 @ =0x04000200
	b _0823E67C
	.align 2, 0
_0823E66C: .4byte 0x04000208
_0823E670: .4byte 0x04000200
_0823E674:
	movs r0, #0xc8
	bl FUN_0823d8f4
	adds r7, #1
_0823E67C:
	cmp r7, #4
	bgt _0823E6A8
	mov r1, r8
	mov r0, sb
	strh r1, [r0]
	ldrh r4, [r6]
	strh r1, [r6]
	bl FUN_0823d904
	ldr r0, _0823E764 @ =0x03004810
	bl FUN_0824c898
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	bl FUN_0823d910
	strh r4, [r6]
	movs r0, #1
	mov r1, sb
	strh r0, [r1]
	cmp r5, #1
	bne _0823E674
_0823E6A8:
	bl FUN_0824172c
	cmp r5, #1
	bne _0823E754
	ldr r1, _0823E764 @ =0x03004810
	ldrb r2, [r1]
	movs r0, #0xf0
	ands r0, r2
	cmp r0, #0x9f
	bhi _0823E6C4
	movs r0, #0xf
	ands r0, r2
	cmp r0, #9
	bls _0823E6CC
_0823E6C4:
	movs r5, #2
	rsbs r5, r5, #0
	movs r0, #0
	strb r0, [r1]
_0823E6CC:
	ldrb r2, [r1, #1]
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x11
	bhi _0823E6E0
	movs r0, #0xf
	ands r0, r2
	cmp r0, #9
	bls _0823E6E8
_0823E6E0:
	movs r5, #3
	rsbs r5, r5, #0
	movs r0, #1
	strb r0, [r1, #1]
_0823E6E8:
	ldrb r2, [r1, #2]
	subs r0, r2, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x30
	bhi _0823E6FC
	movs r0, #0xf
	ands r0, r2
	cmp r0, #9
	bls _0823E704
_0823E6FC:
	movs r5, #4
	rsbs r5, r5, #0
	movs r0, #1
	strb r0, [r1, #2]
_0823E704:
	ldrb r0, [r1, #3]
	cmp r0, #7
	bne _0823E712
	movs r5, #5
	rsbs r5, r5, #0
	movs r0, #0
	strb r0, [r1, #3]
_0823E712:
	ldrb r2, [r1, #4]
	cmp r2, #0x23
	bhi _0823E720
	movs r0, #0xf
	ands r0, r2
	cmp r0, #9
	bls _0823E728
_0823E720:
	movs r5, #6
	rsbs r5, r5, #0
	movs r0, #0
	strb r0, [r1, #4]
_0823E728:
	ldrb r2, [r1, #5]
	cmp r2, #0x5f
	bhi _0823E736
	movs r0, #0xf
	ands r0, r2
	cmp r0, #9
	bls _0823E73E
_0823E736:
	movs r5, #7
	rsbs r5, r5, #0
	movs r0, #0
	strb r0, [r1, #5]
_0823E73E:
	ldrb r2, [r1, #6]
	cmp r2, #0x5f
	bhi _0823E74C
	movs r0, #0xf
	ands r0, r2
	cmp r0, #9
	bls _0823E754
_0823E74C:
	movs r5, #8
	rsbs r5, r5, #0
	movs r0, #0
	strb r0, [r1, #6]
_0823E754:
	adds r0, r5, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823E764: .4byte 0x03004810

	thumb_func_start FUN_0823e768
FUN_0823e768: @ 0x0823E768
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	bl FUN_0823e650
	adds r7, r0, #0
	cmp r7, #1
	bne _0823E7F4
	ldr r0, _0823E808 @ =0x03004810
	mov sb, r0
	ldrb r0, [r0]
	bl FUN_0823d930
	adds r5, r0, #0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	movs r1, #0xfa
	lsls r1, r1, #3
	adds r5, r5, r1
	mov r1, sb
	ldrb r0, [r1, #1]
	bl FUN_0823d930
	mov sl, r0
	mov r0, sl
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov sl, r0
	mov r1, sb
	ldrb r0, [r1, #2]
	bl FUN_0823d930
	mov r8, r0
	mov r0, r8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	mov r1, sb
	ldrb r0, [r1, #4]
	bl FUN_0823d930
	adds r6, r0, #0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	mov r1, sb
	ldrb r0, [r1, #5]
	bl FUN_0823d930
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r1, sb
	ldrb r0, [r1, #6]
	bl FUN_0823d930
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r4, [sp]
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	adds r0, r5, #0
	mov r1, sl
	mov r2, r8
	adds r3, r6, #0
	bl FUN_0823e038
_0823E7F4:
	adds r0, r7, #0
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0823E808: .4byte 0x03004810

	thumb_func_start FUN_0823e80c
FUN_0823e80c: @ 0x0823E80C
	push {lr}
	ldr r0, _0823E81C @ =0x030047E0
	ldrb r0, [r0, #4]
	cmp r0, #2
	bls _0823E820
	movs r0, #0
	b _0823E822
	.align 2, 0
_0823E81C: .4byte 0x030047E0
_0823E820:
	movs r0, #1
_0823E822:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823e828
FUN_0823e828: @ 0x0823E828
	push {r4, r5, lr}
	bl FUN_0823d904
	bl FUN_0824c5c8
	lsls r5, r0, #0x18
	lsrs r4, r5, #0x18
	bl FUN_0823d910
	movs r0, #0xf
	ands r4, r0
	cmp r4, #1
	beq _0823E846
	subs r0, #0x10
	b _0823E848
_0823E846:
	movs r0, #1
_0823E848:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0823e850
FUN_0823e850: @ 0x0823E850
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r0, r1, #0
	adds r7, r3, #0
	cmp r2, #2
	bgt _0823E864
	subs r5, r0, #1
	adds r6, r2, #0
	adds r6, #0xc
	b _0823E868
_0823E864:
	adds r5, r0, #0
	adds r6, r2, #0
_0823E868:
	adds r0, r5, #0
	bl FUN_0824dcc8
	cmp r5, #0
	bge _0823E87A
	ldr r3, _0823E92C @ =0x00000000
	ldr r2, _0823E928 @ =0x41F00000
	bl FUN_0824d53c
_0823E87A:
	ldr r2, _0823E930 @ =0x4076D400
	ldr r3, _0823E934 @ =0x00000000
	bl FUN_0824d5a4
	bl FUN_0824cf34
	adds r4, r0, #0
	movs r1, #0xc8
	lsls r1, r1, #1
	adds r0, r5, #0
	bl __udivsi3
	adds r4, r4, r0
	adds r0, r5, #0
	movs r1, #0x64
	bl __udivsi3
	subs r4, r4, r0
	adds r0, r4, #0
	bl FUN_0824dcc8
	str r0, [sp]
	str r1, [sp, #4]
	cmp r4, #0
	bge _0823E8B8
	ldr r3, _0823E92C @ =0x00000000
	ldr r2, _0823E928 @ =0x41F00000
	bl FUN_0824d53c
	str r0, [sp]
	str r1, [sp, #4]
_0823E8B8:
	subs r4, r6, #2
	adds r0, r4, #0
	bl FUN_0824dcc8
	cmp r4, #0
	bge _0823E8CC
	ldr r3, _0823E92C @ =0x00000000
	ldr r2, _0823E928 @ =0x41F00000
	bl FUN_0824d53c
_0823E8CC:
	ldr r2, _0823E938 @ =0x403E970A
	ldr r3, _0823E93C @ =0x3D70A3D7
	bl FUN_0824d5a4
	bl FUN_0824cf34
	adds r4, r0, #0
	bl FUN_0824dcc8
	adds r6, r1, #0
	adds r5, r0, #0
	cmp r4, #0
	bge _0823E8F2
	ldr r3, _0823E92C @ =0x00000000
	ldr r2, _0823E928 @ =0x41F00000
	bl FUN_0824d53c
	adds r6, r1, #0
	adds r5, r0, #0
_0823E8F2:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r6, #0
	adds r2, r5, #0
	bl FUN_0824d53c
	adds r5, r1, #0
	adds r4, r0, #0
	adds r0, r7, #0
	bl FUN_0824dcc8
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d53c
	ldr r2, _0823E940 @ =0x4124B800
	ldr r3, _0823E944 @ =0x00000000
	bl FUN_0824d56c
	str r0, [sp]
	str r1, [sp, #4]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r2}
	bx r2
	.align 2, 0
_0823E928: .4byte 0x41F00000
_0823E92C: .4byte 0x00000000
_0823E930: .4byte 0x4076D400
_0823E934: .4byte 0x00000000
_0823E938: .4byte 0x403E970A
_0823E93C: .4byte 0x3D70A3D7
_0823E940: .4byte 0x4124B800
_0823E944: .4byte 0x00000000

	thumb_func_start FUN_0823e948
FUN_0823e948: @ 0x0823E948
	push {r4, r5, r6, r7, lr}
	ldr r3, _0823E9BC @ =0x00000000
	ldr r2, _0823E9B8 @ =0x40E92B10
	bl FUN_0824d56c
	ldr r2, _0823E9C0 @ =0x3F4845C7
	ldr r3, _0823E9C4 @ =0x0994535F
	bl FUN_0824d53c
	ldr r2, _0823E9C8 @ =0x40E1D5A0
	ldr r3, _0823E9CC @ =0x00000000
	bl FUN_0824d84c
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r2, _0823E9D0 @ =0x3F8A9FBE
	ldr r3, _0823E9D4 @ =0x76C8B439
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, _0823E9D8 @ =0x40377075
	ldr r1, _0823E9DC @ =0xF6FD21FF
	bl FUN_0824d56c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823E9E0 @ =0x409E3800
	ldr r3, _0823E9E4 @ =0x00000000
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d5a4
	ldr r2, _0823E9E8 @ =0x406D6000
	ldr r3, _0823E9EC @ =0x00000000
	bl FUN_0824d53c
	ldr r2, _0823E9F0 @ =0x3F91DF46
	ldr r3, _0823E9F4 @ =0xA2529D34
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823E9F8 @ =0x3F654C98
	ldr r3, _0823E9FC @ =0x5F06F694
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	pop {r4, r5, r6, r7}
	pop {r2}
	bx r2
	.align 2, 0
_0823E9B8: .4byte 0x40E92B10
_0823E9BC: .4byte 0x00000000
_0823E9C0: .4byte 0x3F4845C7
_0823E9C4: .4byte 0x0994535F
_0823E9C8: .4byte 0x40E1D5A0
_0823E9CC: .4byte 0x00000000
_0823E9D0: .4byte 0x3F8A9FBE
_0823E9D4: .4byte 0x76C8B439
_0823E9D8: .4byte 0x40377075
_0823E9DC: .4byte 0xF6FD21FF
_0823E9E0: .4byte 0x409E3800
_0823E9E4: .4byte 0x00000000
_0823E9E8: .4byte 0x406D6000
_0823E9EC: .4byte 0x00000000
_0823E9F0: .4byte 0x3F91DF46
_0823E9F4: .4byte 0xA2529D34
_0823E9F8: .4byte 0x3F654C98
_0823E9FC: .4byte 0x5F06F694

	thumb_func_start FUN_0823ea00
FUN_0823ea00: @ 0x0823EA00
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r3, _0823ED74 @ =0x00000000
	ldr r2, _0823ED70 @ =0x40E92B10
	bl FUN_0824d56c
	ldr r2, _0823ED78 @ =0x3F4845C7
	ldr r3, _0823ED7C @ =0x0994535F
	bl FUN_0824d53c
	ldr r2, _0823ED80 @ =0x40E1D5A0
	ldr r3, _0823ED84 @ =0x00000000
	bl FUN_0824d84c
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, _0823ED88 @ =0x411D5FCF
	ldr r3, _0823ED8C @ =0x863F1412
	bl FUN_0824d5a4
	ldr r2, _0823ED90 @ =0x406B4A21
	ldr r3, _0823ED94 @ =0x9652BD3C
	bl FUN_0824d53c
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r2, _0823ED98 @ =0x3F589374
	ldr r3, _0823ED9C @ =0xBC6A7EFA
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, [sp]
	ldr r3, [sp, #4]
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d56c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EDA0 @ =0x411D203B
	ldr r3, _0823EDA4 @ =0x78D4FDF4
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823EDA8 @ =0x40467B43
	ldr r3, _0823EDAC @ =0x95810625
	bl FUN_0824d53c
	ldr r4, _0823EDB0 @ =0x3F91DF46
	ldr r5, _0823EDB4 @ =0xA2529D34
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823EDB8 @ =0x401927BB
	ldr r3, _0823EDBC @ =0x2FEC56D6
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EDC0 @ =0x41193A5D
	ldr r3, _0823EDC4 @ =0x66666666
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823EDC8 @ =0x40257AE1
	ldr r3, _0823EDCC @ =0x47AE147B
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823EDD0 @ =0x3FF4624D
	ldr r3, _0823EDD4 @ =0xD2F1A9FC
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EDD8 @ =0x412B2D4C
	ldr r3, _0823EDDC @ =0x70A3D70A
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823EDE0 @ =0x40623666
	ldr r3, _0823EDE4 @ =0x66666666
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823EDE8 @ =0x3FE510CB
	ldr r3, _0823EDEC @ =0x295E9E1B
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EDF0 @ =0x412D203B
	ldr r3, _0823EDF4 @ =0x7AE147AE
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823EDF8 @ =0x40667DC2
	ldr r3, _0823EDFC @ =0x8F5C28F6
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823EE00 @ =0x3FCB573E
	ldr r3, _0823EE04 @ =0xAB367A10
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EE08 @ =0x40E193E1
	ldr r3, _0823EE0C @ =0x9999999A
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823EE10 @ =0x4055E1EB
	ldr r3, _0823EE14 @ =0x851EB852
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823EE18 @ =0x3FC7B15B
	ldr r3, _0823EE1C @ =0x573EAB36
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EE20 @ =0x412D7E08
	ldr r3, _0823EE24 @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823EE28 @ =0x40714800
	ldr r3, _0823EE2C @ =0x00000000
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823EE30 @ =0x3FBD4951
	ldr r3, _0823EE34 @ =0x82A9930C
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EE38 @ =0x40EF2EF0
	ldr r3, _0823EE3C @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823EE40 @ =0x405F0CCC
	ldr r3, _0823EE44 @ =0xCCCCCCCD
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823EE48 @ =0x3FAE1B08
	ldr r3, _0823EE4C @ =0x9A027525
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EE50 @ =0x411707E1
	ldr r3, _0823EE54 @ =0x33333333
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823EE58 @ =0x402A6666
	ldr r3, _0823EE5C @ =0x66666666
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823EE60 @ =0x3FAD3C36
	ldr r3, _0823EE64 @ =0x113404EA
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EE68 @ =0x4134DEB5
	ldr r3, _0823EE6C @ =0x1999999A
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823EE70 @ =0x40718B33
	ldr r3, _0823EE74 @ =0x33333333
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823EE78 @ =0x3FAB4A23
	ldr r3, _0823EE7C @ =0x39C0EBEE
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EE80 @ =0x412A140E
	ldr r3, _0823EE84 @ =0x66666666
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823EE88 @ =0x40628666
	ldr r3, _0823EE8C @ =0x66666666
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823EE90 @ =0x3FA77318
	ldr r3, _0823EE94 @ =0xFC504817
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EE98 @ =0x411AEDBF
	ldr r3, _0823EE9C @ =0x33333333
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823EEA0 @ =0x4047B333
	ldr r3, _0823EEA4 @ =0x33333333
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823EEA8 @ =0x3FA4F0D8
	ldr r3, _0823EEAC @ =0x44D013A9
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EEB0 @ =0x411B2D4C
	ldr r3, _0823EEB4 @ =0x66666666
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823EEB8 @ =0x403BE666
	ldr r3, _0823EEBC @ =0x66666666
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823EEC0 @ =0x3FA1C432
	ldr r3, _0823EEC4 @ =0xCA57A787
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EEC8 @ =0x411F52B7
	ldr r3, _0823EECC @ =0x9999999A
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823EED0 @ =0x406BD000
	ldr r3, _0823EED4 @ =0x00000000
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823EED8 @ =0x3F9F212D
	ldr r3, _0823EEDC @ =0x77318FC5
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823EEE0 @ =0x40F285E0
	ldr r3, _0823EEE4 @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823EEE8 @ =0x40448000
	ldr r3, _0823EEEC @ =0x00000000
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823EEF0 @ =0x3F8F8A09
	ldr r3, _0823EEF4 @ =0x02DE00D2
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	b _0823EEF8
	.align 2, 0
_0823ED70: .4byte 0x40E92B10
_0823ED74: .4byte 0x00000000
_0823ED78: .4byte 0x3F4845C7
_0823ED7C: .4byte 0x0994535F
_0823ED80: .4byte 0x40E1D5A0
_0823ED84: .4byte 0x00000000
_0823ED88: .4byte 0x411D5FCF
_0823ED8C: .4byte 0x863F1412
_0823ED90: .4byte 0x406B4A21
_0823ED94: .4byte 0x9652BD3C
_0823ED98: .4byte 0x3F589374
_0823ED9C: .4byte 0xBC6A7EFA
_0823EDA0: .4byte 0x411D203B
_0823EDA4: .4byte 0x78D4FDF4
_0823EDA8: .4byte 0x40467B43
_0823EDAC: .4byte 0x95810625
_0823EDB0: .4byte 0x3F91DF46
_0823EDB4: .4byte 0xA2529D34
_0823EDB8: .4byte 0x401927BB
_0823EDBC: .4byte 0x2FEC56D6
_0823EDC0: .4byte 0x41193A5D
_0823EDC4: .4byte 0x66666666
_0823EDC8: .4byte 0x40257AE1
_0823EDCC: .4byte 0x47AE147B
_0823EDD0: .4byte 0x3FF4624D
_0823EDD4: .4byte 0xD2F1A9FC
_0823EDD8: .4byte 0x412B2D4C
_0823EDDC: .4byte 0x70A3D70A
_0823EDE0: .4byte 0x40623666
_0823EDE4: .4byte 0x66666666
_0823EDE8: .4byte 0x3FE510CB
_0823EDEC: .4byte 0x295E9E1B
_0823EDF0: .4byte 0x412D203B
_0823EDF4: .4byte 0x7AE147AE
_0823EDF8: .4byte 0x40667DC2
_0823EDFC: .4byte 0x8F5C28F6
_0823EE00: .4byte 0x3FCB573E
_0823EE04: .4byte 0xAB367A10
_0823EE08: .4byte 0x40E193E1
_0823EE0C: .4byte 0x9999999A
_0823EE10: .4byte 0x4055E1EB
_0823EE14: .4byte 0x851EB852
_0823EE18: .4byte 0x3FC7B15B
_0823EE1C: .4byte 0x573EAB36
_0823EE20: .4byte 0x412D7E08
_0823EE24: .4byte 0x00000000
_0823EE28: .4byte 0x40714800
_0823EE2C: .4byte 0x00000000
_0823EE30: .4byte 0x3FBD4951
_0823EE34: .4byte 0x82A9930C
_0823EE38: .4byte 0x40EF2EF0
_0823EE3C: .4byte 0x00000000
_0823EE40: .4byte 0x405F0CCC
_0823EE44: .4byte 0xCCCCCCCD
_0823EE48: .4byte 0x3FAE1B08
_0823EE4C: .4byte 0x9A027525
_0823EE50: .4byte 0x411707E1
_0823EE54: .4byte 0x33333333
_0823EE58: .4byte 0x402A6666
_0823EE5C: .4byte 0x66666666
_0823EE60: .4byte 0x3FAD3C36
_0823EE64: .4byte 0x113404EA
_0823EE68: .4byte 0x4134DEB5
_0823EE6C: .4byte 0x1999999A
_0823EE70: .4byte 0x40718B33
_0823EE74: .4byte 0x33333333
_0823EE78: .4byte 0x3FAB4A23
_0823EE7C: .4byte 0x39C0EBEE
_0823EE80: .4byte 0x412A140E
_0823EE84: .4byte 0x66666666
_0823EE88: .4byte 0x40628666
_0823EE8C: .4byte 0x66666666
_0823EE90: .4byte 0x3FA77318
_0823EE94: .4byte 0xFC504817
_0823EE98: .4byte 0x411AEDBF
_0823EE9C: .4byte 0x33333333
_0823EEA0: .4byte 0x4047B333
_0823EEA4: .4byte 0x33333333
_0823EEA8: .4byte 0x3FA4F0D8
_0823EEAC: .4byte 0x44D013A9
_0823EEB0: .4byte 0x411B2D4C
_0823EEB4: .4byte 0x66666666
_0823EEB8: .4byte 0x403BE666
_0823EEBC: .4byte 0x66666666
_0823EEC0: .4byte 0x3FA1C432
_0823EEC4: .4byte 0xCA57A787
_0823EEC8: .4byte 0x411F52B7
_0823EECC: .4byte 0x9999999A
_0823EED0: .4byte 0x406BD000
_0823EED4: .4byte 0x00000000
_0823EED8: .4byte 0x3F9F212D
_0823EEDC: .4byte 0x77318FC5
_0823EEE0: .4byte 0x40F285E0
_0823EEE4: .4byte 0x00000000
_0823EEE8: .4byte 0x40448000
_0823EEEC: .4byte 0x00000000
_0823EEF0: .4byte 0x3F8F8A09
_0823EEF4: .4byte 0x02DE00D2
_0823EEF8:
	ldr r3, _0823F12C @ =0x00000000
	ldr r2, _0823F128 @ =0x41360713
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823F130 @ =0x404A0000
	ldr r3, _0823F134 @ =0x00000000
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823F138 @ =0x3F899999
	ldr r3, _0823F13C @ =0x9999999A
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F140 @ =0x411DDBD4
	ldr r3, _0823F144 @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823F148 @ =0x4061C000
	ldr r3, _0823F14C @ =0x00000000
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823F150 @ =0x3F86872B
	ldr r3, _0823F154 @ =0x020C49BA
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F158 @ =0x4133E53E
	ldr r3, _0823F15C @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823F160 @ =0x406EC000
	ldr r3, _0823F164 @ =0x00000000
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823F168 @ =0x3F85E9E1
	ldr r3, _0823F16C @ =0xB089A027
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F170 @ =0x4135D82D
	ldr r3, _0823F174 @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823F178 @ =0x4073B000
	ldr r3, _0823F17C @ =0x00000000
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823F180 @ =0x3F847AE1
	ldr r3, _0823F184 @ =0x47AE147B
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F188 @ =0x41293A5E
	ldr r3, _0823F18C @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823F190 @ =0x405BC000
	ldr r3, _0823F194 @ =0x00000000
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823F198 @ =0x3F816872
	ldr r3, _0823F19C @ =0xB020C49C
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F1A0 @ =0x411B6CD8
	ldr r3, _0823F1A4 @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823F1A8 @ =0x40678000
	ldr r3, _0823F1AC @ =0x00000000
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823F1B0 @ =0x3F802DE0
	ldr r3, _0823F1B4 @ =0x0D1B7176
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F1B8 @ =0x412C468A
	ldr r3, _0823F1BC @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823F1C0 @ =0x40743000
	ldr r3, _0823F1C4 @ =0x00000000
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823F1C8 @ =0x3F7BDA51
	ldr r3, _0823F1CC @ =0x19CE075F
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F1D0 @ =0x40DF2F00
	ldr r3, _0823F1D4 @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823F1D8 @ =0x405AC000
	ldr r3, _0823F1DC @ =0x00000000
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823F1E0 @ =0x3F754C98
	ldr r3, _0823F1E4 @ =0x5F06F694
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F1E8 @ =0x411D5FC8
	ldr r3, _0823F1EC @ =0x00000000
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	ldr r2, _0823F1F0 @ =0x4069A000
	ldr r3, _0823F1F4 @ =0x00000000
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	bl FUN_0824ebc8
	ldr r2, _0823F1F8 @ =0x3F747AE1
	ldr r3, _0823F1FC @ =0x47AE147B
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r4, _0823F200 @ =0x40768000
	ldr r5, _0823F204 @ =0x00000000
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824ef24
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F208 @ =0x00000000
	ldr r3, _0823F20C @ =0x00000000
	bl FUN_0824dc30
	cmp r0, #0
	bge _0823F11C
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
_0823F11C:
	adds r1, r7, #0
	adds r0, r6, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r2}
	bx r2
	.align 2, 0
_0823F128: .4byte 0x41360713
_0823F12C: .4byte 0x00000000
_0823F130: .4byte 0x404A0000
_0823F134: .4byte 0x00000000
_0823F138: .4byte 0x3F899999
_0823F13C: .4byte 0x9999999A
_0823F140: .4byte 0x411DDBD4
_0823F144: .4byte 0x00000000
_0823F148: .4byte 0x4061C000
_0823F14C: .4byte 0x00000000
_0823F150: .4byte 0x3F86872B
_0823F154: .4byte 0x020C49BA
_0823F158: .4byte 0x4133E53E
_0823F15C: .4byte 0x00000000
_0823F160: .4byte 0x406EC000
_0823F164: .4byte 0x00000000
_0823F168: .4byte 0x3F85E9E1
_0823F16C: .4byte 0xB089A027
_0823F170: .4byte 0x4135D82D
_0823F174: .4byte 0x00000000
_0823F178: .4byte 0x4073B000
_0823F17C: .4byte 0x00000000
_0823F180: .4byte 0x3F847AE1
_0823F184: .4byte 0x47AE147B
_0823F188: .4byte 0x41293A5E
_0823F18C: .4byte 0x00000000
_0823F190: .4byte 0x405BC000
_0823F194: .4byte 0x00000000
_0823F198: .4byte 0x3F816872
_0823F19C: .4byte 0xB020C49C
_0823F1A0: .4byte 0x411B6CD8
_0823F1A4: .4byte 0x00000000
_0823F1A8: .4byte 0x40678000
_0823F1AC: .4byte 0x00000000
_0823F1B0: .4byte 0x3F802DE0
_0823F1B4: .4byte 0x0D1B7176
_0823F1B8: .4byte 0x412C468A
_0823F1BC: .4byte 0x00000000
_0823F1C0: .4byte 0x40743000
_0823F1C4: .4byte 0x00000000
_0823F1C8: .4byte 0x3F7BDA51
_0823F1CC: .4byte 0x19CE075F
_0823F1D0: .4byte 0x40DF2F00
_0823F1D4: .4byte 0x00000000
_0823F1D8: .4byte 0x405AC000
_0823F1DC: .4byte 0x00000000
_0823F1E0: .4byte 0x3F754C98
_0823F1E4: .4byte 0x5F06F694
_0823F1E8: .4byte 0x411D5FC8
_0823F1EC: .4byte 0x00000000
_0823F1F0: .4byte 0x4069A000
_0823F1F4: .4byte 0x00000000
_0823F1F8: .4byte 0x3F747AE1
_0823F1FC: .4byte 0x47AE147B
_0823F200: .4byte 0x40768000
_0823F204: .4byte 0x00000000
_0823F208: .4byte 0x00000000
_0823F20C: .4byte 0x00000000

	thumb_func_start FUN_0823f210
FUN_0823f210: @ 0x0823F210
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	ldr r3, _0823F348 @ =0x00000000
	ldr r2, _0823F344 @ =0x40E92B10
	bl FUN_0824d56c
	ldr r2, _0823F34C @ =0x3F4845C7
	ldr r3, _0823F350 @ =0x0994535F
	bl FUN_0824d53c
	ldr r2, _0823F354 @ =0x4076D400
	ldr r3, _0823F358 @ =0x00000000
	bl FUN_0824d84c
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r2, _0823F35C @ =0x4076801F
	ldr r3, _0823F360 @ =0x7F8CA81A
	bl FUN_0824d5a4
	ldr r2, _0823F364 @ =0x4071875D
	ldr r3, _0823F368 @ =0x63886595
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F36C @ =0x3F0A36E2
	ldr r3, _0823F370 @ =0xEB1C432D
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, _0823F374 @ =0x3FFEA233
	ldr r1, _0823F378 @ =0x9C0EBEE0
	bl FUN_0824d56c
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, _0823F37C @ =0x40767FDB
	ldr r3, _0823F380 @ =0x22D0E560
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d5a4
	ldr r2, _0823F384 @ =0x4076589B
	ldr r3, _0823F388 @ =0xA5E353F8
	bl FUN_0824d53c
	ldr r2, _0823F38C @ =0x3F91DF46
	ldr r3, _0823F390 @ =0xA2529D34
	bl FUN_0824d5a4
	bl FUN_0824ec90
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F394 @ =0x40867FD9
	ldr r3, _0823F398 @ =0x16872B02
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d5a4
	ldr r2, _0823F39C @ =0x407630CC
	ldr r3, _0823F3A0 @ =0xCCCCCCCD
	bl FUN_0824d53c
	ldr r2, _0823F38C @ =0x3F91DF46
	ldr r3, _0823F390 @ =0xA2529D34
	bl FUN_0824d5a4
	bl FUN_0824ec90
	ldr r2, _0823F3A4 @ =0x3F947AE1
	ldr r3, _0823F3A8 @ =0x47AE147B
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F3AC @ =0x4033574B
	ldr r3, _0823F3B0 @ =0xC6A7EF9E
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d5a4
	ldr r2, _0823F3B4 @ =0x406D5E66
	ldr r3, _0823F3B8 @ =0x66666666
	bl FUN_0824d53c
	ldr r2, _0823F38C @ =0x3F91DF46
	ldr r3, _0823F390 @ =0xA2529D34
	bl FUN_0824d5a4
	bl FUN_0824ec90
	ldr r2, _0823F3BC @ =0x3F73A92A
	ldr r3, _0823F3C0 @ =0x30553261
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r4, _0823F3C4 @ =0x40768000
	ldr r5, _0823F3C8 @ =0x00000000
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824ef24
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823F3CC @ =0x00000000
	ldr r3, _0823F3D0 @ =0x00000000
	bl FUN_0824dc30
	cmp r0, #0
	bge _0823F338
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
_0823F338:
	adds r1, r7, #0
	adds r0, r6, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r2}
	bx r2
	.align 2, 0
_0823F344: .4byte 0x40E92B10
_0823F348: .4byte 0x00000000
_0823F34C: .4byte 0x3F4845C7
_0823F350: .4byte 0x0994535F
_0823F354: .4byte 0x4076D400
_0823F358: .4byte 0x00000000
_0823F35C: .4byte 0x4076801F
_0823F360: .4byte 0x7F8CA81A
_0823F364: .4byte 0x4071875D
_0823F368: .4byte 0x63886595
_0823F36C: .4byte 0x3F0A36E2
_0823F370: .4byte 0xEB1C432D
_0823F374: .4byte 0x3FFEA233
_0823F378: .4byte 0x9C0EBEE0
_0823F37C: .4byte 0x40767FDB
_0823F380: .4byte 0x22D0E560
_0823F384: .4byte 0x4076589B
_0823F388: .4byte 0xA5E353F8
_0823F38C: .4byte 0x3F91DF46
_0823F390: .4byte 0xA2529D34
_0823F394: .4byte 0x40867FD9
_0823F398: .4byte 0x16872B02
_0823F39C: .4byte 0x407630CC
_0823F3A0: .4byte 0xCCCCCCCD
_0823F3A4: .4byte 0x3F947AE1
_0823F3A8: .4byte 0x47AE147B
_0823F3AC: .4byte 0x4033574B
_0823F3B0: .4byte 0xC6A7EF9E
_0823F3B4: .4byte 0x406D5E66
_0823F3B8: .4byte 0x66666666
_0823F3BC: .4byte 0x3F73A92A
_0823F3C0: .4byte 0x30553261
_0823F3C4: .4byte 0x40768000
_0823F3C8: .4byte 0x00000000
_0823F3CC: .4byte 0x00000000
_0823F3D0: .4byte 0x00000000

	thumb_func_start FUN_0823f3d4
FUN_0823f3d4: @ 0x0823F3D4
	ldr r1, _0823F3E0 @ =0x00000000
	ldr r0, _0823F3DC @ =0x00000000
	bx lr
	.align 2, 0
_0823F3DC: .4byte 0x00000000
_0823F3E0: .4byte 0x00000000

	thumb_func_start FUN_0823f3e4
FUN_0823f3e4: @ 0x0823F3E4
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	bl FUN_0823e850
	ldr r3, _0823F40C @ =0x00000000
	ldr r2, _0823F408 @ =0x3FE00000
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	str r6, [sp]
	str r7, [sp, #4]
	movs r0, #1
	mov r8, r0
	b _0823F450
	.align 2, 0
_0823F408: .4byte 0x3FE00000
_0823F40C: .4byte 0x00000000
_0823F410:
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r3, _0823F510 @ =0x00000000
	ldr r2, _0823F50C @ =0x00000000
	bl FUN_0824dc30
	cmp r0, #0
	bge _0823F430
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823F514 @ =0xBFB99999
	ldr r3, _0823F518 @ =0x9999999A
	bl FUN_0824dbe4
	cmp r0, #0
	bge _0823F496
_0823F430:
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823F51C @ =0x40285D14
	ldr r3, _0823F520 @ =0xE3BCD35B
	bl FUN_0824d84c
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d56c
	adds r7, r1, #0
	adds r6, r0, #0
	movs r0, #1
	add r8, r0
_0823F450:
	mov r0, r8
	cmp r0, #6
	bgt _0823F496
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0823ea00
	adds r5, r1, #0
	adds r4, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0823f210
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d56c
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r3, _0823F510 @ =0x00000000
	ldr r2, _0823F50C @ =0x00000000
	bl FUN_0824dbe4
	cmp r0, #0
	blt _0823F410
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823F524 @ =0x3FB99999
	ldr r3, _0823F528 @ =0x9999999A
	bl FUN_0824dc7c
	cmp r0, #0
	bgt _0823F410
_0823F496:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r7, #0
	adds r2, r6, #0
	bl FUN_0824d56c
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r3, _0823F510 @ =0x00000000
	ldr r2, _0823F50C @ =0x00000000
	bl FUN_0824dc30
	cmp r0, #0
	blt _0823F4C4
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823F52C @ =0x403D8D62
	ldr r3, _0823F530 @ =0x69BD25B0
	bl FUN_0824db98
	cmp r0, #0
	bgt _0823F4C4
	b _0823F5DA
_0823F4C4:
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r3, _0823F510 @ =0x00000000
	ldr r2, _0823F50C @ =0x00000000
	bl FUN_0824dc30
	cmp r0, #0
	bge _0823F534
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, _0823F52C @ =0x403D8D62
	ldr r3, _0823F530 @ =0x69BD25B0
	bl FUN_0824d56c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, _0823F52C @ =0x403D8D62
	ldr r1, _0823F530 @ =0x69BD25B0
	bl FUN_0824ddb8
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824dc30
	cmp r0, #0
	bge _0823F544
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, _0823F52C @ =0x403D8D62
	ldr r3, _0823F530 @ =0x69BD25B0
	bl FUN_0824d56c
	b _0823F540
	.align 2, 0
_0823F50C: .4byte 0x00000000
_0823F510: .4byte 0x00000000
_0823F514: .4byte 0xBFB99999
_0823F518: .4byte 0x9999999A
_0823F51C: .4byte 0x40285D14
_0823F520: .4byte 0xE3BCD35B
_0823F524: .4byte 0x3FB99999
_0823F528: .4byte 0x9999999A
_0823F52C: .4byte 0x403D8D62
_0823F530: .4byte 0x69BD25B0
_0823F534:
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r3, _0823F550 @ =0x69BD25B0
	ldr r2, _0823F54C @ =0x403D8D62
	bl FUN_0824d53c
_0823F540:
	adds r7, r1, #0
	adds r6, r0, #0
_0823F544:
	movs r0, #1
	mov r8, r0
	b _0823F594
	.align 2, 0
_0823F54C: .4byte 0x403D8D62
_0823F550: .4byte 0x69BD25B0
_0823F554:
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r3, _0823F5FC @ =0x00000000
	ldr r2, _0823F5F8 @ =0x00000000
	bl FUN_0824dc30
	cmp r0, #0
	bge _0823F574
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823F600 @ =0xBFB99999
	ldr r3, _0823F604 @ =0x9999999A
	bl FUN_0824dbe4
	cmp r0, #0
	bge _0823F5DA
_0823F574:
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823F608 @ =0x40285D14
	ldr r3, _0823F60C @ =0xE3BCD35B
	bl FUN_0824d84c
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d56c
	adds r7, r1, #0
	adds r6, r0, #0
	movs r0, #1
	add r8, r0
_0823F594:
	mov r0, r8
	cmp r0, #4
	bgt _0823F5DA
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0823ea00
	adds r5, r1, #0
	adds r4, r0, #0
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0823f210
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d56c
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r3, _0823F5FC @ =0x00000000
	ldr r2, _0823F5F8 @ =0x00000000
	bl FUN_0824dbe4
	cmp r0, #0
	blt _0823F554
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823F610 @ =0x3FB99999
	ldr r3, _0823F614 @ =0x9999999A
	bl FUN_0824dc7c
	cmp r0, #0
	bgt _0823F554
_0823F5DA:
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r7, #0
	adds r2, r6, #0
	bl FUN_0824d56c
	adds r5, r1, #0
	adds r4, r0, #0
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r2}
	bx r2
	.align 2, 0
_0823F5F8: .4byte 0x00000000
_0823F5FC: .4byte 0x00000000
_0823F600: .4byte 0xBFB99999
_0823F604: .4byte 0x9999999A
_0823F608: .4byte 0x40285D14
_0823F60C: .4byte 0xE3BCD35B
_0823F610: .4byte 0x3FB99999
_0823F614: .4byte 0x9999999A

	thumb_func_start FUN_0823f618
FUN_0823f618: @ 0x0823F618
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x90
	mov r8, r0
	mov sb, r1
	adds r5, r3, #0
	adds r4, r2, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0823f210
	str r0, [sp]
	str r1, [sp, #4]
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0823f3d4
	adds r7, r1, #0
	adds r6, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0823e948
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r5, _0823F8FC @ =0x1A63C200
	ldr r4, _0823F8F8 @ =0x404CA5DC
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d84c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, [sp]
	ldr r1, [sp, #4]
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d84c
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d84c
	str r0, [sp, #0x28]
	str r1, [sp, #0x2c]
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824ebc8
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	bl FUN_0824ec90
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d5a4
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	bl FUN_0824ec90
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d5a4
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824ec90
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	bl FUN_0824ebc8
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x30]
	ldr r1, [sp, #0x34]
	bl FUN_0824d53c
	bl FUN_0824ee6c
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824ebc8
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	bl FUN_0824ebc8
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d5a4
	str r0, [sp, #0x38]
	str r1, [sp, #0x3c]
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824ebc8
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x20]
	ldr r1, [sp, #0x24]
	bl FUN_0824ec90
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d5a4
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	bl FUN_0824ebc8
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d5a4
	str r0, [sp, #0x40]
	str r1, [sp, #0x44]
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824ec90
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	bl FUN_0824ec90
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x40]
	ldr r1, [sp, #0x44]
	bl FUN_0824d56c
	ldr r2, [sp, #0x38]
	ldr r3, [sp, #0x3c]
	bl FUN_0824d84c
	bl FUN_0824e854
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r4, _0823F900 @ =0x00000000
	ldr r5, _0823F904 @ =0x00000000
	ldr r0, [sp, #0x38]
	ldr r1, [sp, #0x3c]
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824dc30
	cmp r0, #0
	bge _0823F7B2
	ldr r2, _0823F908 @ =0x400921FB
	ldr r3, _0823F90C @ =0x54442D11
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
_0823F7B2:
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824dc30
	cmp r0, #0
	bge _0823F7D2
	ldr r2, _0823F910 @ =0x401921FB
	ldr r3, _0823F914 @ =0x54442D11
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
_0823F7D2:
	ldr r2, _0823F918 @ =0x3F91DF46
	ldr r3, _0823F91C @ =0xA2529D34
	ldr r0, [sp, #0xb8]
	ldr r1, [sp, #0xbc]
	bl FUN_0824d5a4
	str r0, [sp, #0x48]
	str r1, [sp, #0x4c]
	bl FUN_0824ed44
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	bl FUN_0824ed44
	str r0, [sp, #0x50]
	str r1, [sp, #0x54]
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824ddb8
	ldr r2, [sp, #0x50]
	ldr r3, [sp, #0x54]
	bl FUN_0824d5a4
	str r0, [sp, #0x58]
	str r1, [sp, #0x5c]
	ldr r0, _0823F920 @ =0x3FF95EBF
	ldr r1, _0823F924 @ =0x446C12C1
	bl FUN_0824ebc8
	str r0, [sp, #0x60]
	str r1, [sp, #0x64]
	ldr r0, [sp, #0x48]
	ldr r1, [sp, #0x4c]
	bl FUN_0824ebc8
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	bl FUN_0824ebc8
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d5a4
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x60]
	ldr r1, [sp, #0x64]
	bl FUN_0824d84c
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x58]
	ldr r1, [sp, #0x5c]
	bl FUN_0824d53c
	bl FUN_0824edb4
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	bl FUN_0824d56c
	ldr r4, _0823F910 @ =0x401921FB
	ldr r5, _0823F914 @ =0x54442D11
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d84c
	str r0, [sp, #0x68]
	str r1, [sp, #0x6c]
	mov r2, r8
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d84c
	str r0, [sp, #0x70]
	str r1, [sp, #0x74]
	mov r3, r8
	str r0, [r3, #0x20]
	str r1, [r3, #0x24]
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	bl FUN_0824d53c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d84c
	str r0, [sp, #0x78]
	str r1, [sp, #0x7c]
	mov r4, r8
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	ldr r0, [sp, #0xac]
	bl FUN_0824dcc8
	adds r7, r1, #0
	adds r6, r0, #0
	mov r0, sb
	cmp r0, #1
	bne _0823F97C
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, [sp, #0x68]
	ldr r3, [sp, #0x6c]
	bl FUN_0824d53c
	ldr r2, [r4, #0x48]
	ldr r3, [r4, #0x4c]
	bl FUN_0824dc30
	cmp r0, #0
	bge _0823F930
	ldr r0, [r4, #0x64]
	cmp r0, #0
	bne _0823F930
	ldr r2, _0823F928 @ =0x3FF00000
	ldr r3, _0823F92C @ =0x00000000
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, [r4, #0x60]
	adds r0, #1
	str r0, [r4, #0x60]
	ldr r4, [sp, #0x68]
	ldr r5, [sp, #0x6c]
	b _0823FAA8
	.align 2, 0
_0823F8F8: .4byte 0x404CA5DC
_0823F8FC: .4byte 0x1A63C200
_0823F900: .4byte 0x00000000
_0823F904: .4byte 0x00000000
_0823F908: .4byte 0x400921FB
_0823F90C: .4byte 0x54442D11
_0823F910: .4byte 0x401921FB
_0823F914: .4byte 0x54442D11
_0823F918: .4byte 0x3F91DF46
_0823F91C: .4byte 0xA2529D34
_0823F920: .4byte 0x3FF95EBF
_0823F924: .4byte 0x446C12C1
_0823F928: .4byte 0x3FF00000
_0823F92C: .4byte 0x00000000
_0823F930:
	adds r1, r7, #0
	adds r0, r6, #0
	mov r4, r8
	ldr r2, [r4, #0x18]
	ldr r3, [r4, #0x1c]
	bl FUN_0824d53c
	ldr r2, [r4, #0x50]
	ldr r3, [r4, #0x54]
	bl FUN_0824db98
	ldr r5, [r4, #0x1c]
	ldr r4, [r4, #0x18]
	cmp r0, #0
	bgt _0823F950
	b _0823FAA8
_0823F950:
	mov r1, r8
	ldr r0, [r1, #0x60]
	cmp r0, #0
	beq _0823F95A
	b _0823FAA8
_0823F95A:
	ldr r3, _0823F978 @ =0x00000000
	ldr r2, _0823F974 @ =0x3FF00000
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d56c
	adds r7, r1, #0
	adds r6, r0, #0
	mov r2, r8
	ldr r0, [r2, #0x64]
	adds r0, #1
	str r0, [r2, #0x64]
	b _0823FAA8
	.align 2, 0
_0823F974: .4byte 0x3FF00000
_0823F978: .4byte 0x00000000
_0823F97C:
	mov r3, sb
	cmp r3, #2
	bne _0823F9F4
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, [sp, #0x70]
	ldr r3, [sp, #0x74]
	bl FUN_0824d53c
	adds r5, r1, #0
	adds r4, r0, #0
	mov r0, r8
	ldr r2, [r0, #0x48]
	ldr r3, [r0, #0x4c]
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824dc30
	cmp r0, #0
	bge _0823F9C4
	ldr r3, _0823F9C0 @ =0x00000000
	ldr r2, _0823F9BC @ =0x3FF00000
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r4, [sp, #0x68]
	ldr r5, [sp, #0x6c]
	b _0823FAA8
	.align 2, 0
_0823F9BC: .4byte 0x3FF00000
_0823F9C0: .4byte 0x00000000
_0823F9C4:
	mov r1, r8
	ldr r2, [r1, #0x50]
	ldr r3, [r1, #0x54]
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824db98
	ldr r4, [sp, #0x68]
	ldr r5, [sp, #0x6c]
	cmp r0, #0
	ble _0823FAA8
	ldr r3, _0823F9F0 @ =0x00000000
	ldr r2, _0823F9EC @ =0x3FF00000
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d56c
	adds r7, r1, #0
	adds r6, r0, #0
	b _0823FAA8
	.align 2, 0
_0823F9EC: .4byte 0x3FF00000
_0823F9F0: .4byte 0x00000000
_0823F9F4:
	ldr r4, [sp, #0x68]
	ldr r5, [sp, #0x6c]
	mov r2, sb
	cmp r2, #3
	bne _0823FAA8
	ldr r0, [sp, #0x78]
	ldr r1, [sp, #0x7c]
	ldr r3, _0823FA64 @ =0x00000000
	ldr r2, _0823FA60 @ =0x3FF00000
	bl FUN_0824db98
	cmp r0, #0
	ble _0823FA20
	ldr r0, [sp, #0x78]
	ldr r1, [sp, #0x7c]
	ldr r3, _0823FA64 @ =0x00000000
	ldr r2, _0823FA60 @ =0x3FF00000
	bl FUN_0824d56c
	mov r3, r8
	str r0, [r3, #0x28]
	str r1, [r3, #0x2c]
_0823FA20:
	mov r4, r8
	ldr r2, [r4, #0x28]
	ldr r3, [r4, #0x2c]
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	str r0, [sp, #0x88]
	str r1, [sp, #0x8c]
	ldr r2, [r4, #0x48]
	ldr r3, [r4, #0x4c]
	bl FUN_0824dc30
	cmp r0, #0
	bge _0823FA68
	ldr r0, [r4, #0x6c]
	cmp r0, #0
	bne _0823FA68
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r3, _0823FA64 @ =0x00000000
	ldr r2, _0823FA60 @ =0x3FF00000
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r0, [r4, #0x68]
	adds r0, #1
	str r0, [r4, #0x68]
	ldr r5, [r4, #0x1c]
	ldr r4, [r4, #0x18]
	b _0823FAA8
	.align 2, 0
_0823FA60: .4byte 0x3FF00000
_0823FA64: .4byte 0x00000000
_0823FA68:
	mov r0, r8
	ldr r2, [r0, #0x28]
	ldr r3, [r0, #0x2c]
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	mov r4, r8
	ldr r2, [r4, #0x50]
	ldr r3, [r4, #0x54]
	bl FUN_0824db98
	ldr r5, [r4, #0x1c]
	ldr r4, [r4, #0x18]
	cmp r0, #0
	ble _0823FAA8
	mov r1, r8
	ldr r0, [r1, #0x68]
	cmp r0, #0
	bne _0823FAA8
	ldr r3, _0823FB6C @ =0x00000000
	ldr r2, _0823FB68 @ =0x3FF00000
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d56c
	adds r7, r1, #0
	adds r6, r0, #0
	mov r2, r8
	ldr r0, [r2, #0x6c]
	adds r0, #1
	str r0, [r2, #0x6c]
_0823FAA8:
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d53c
	ldr r2, _0823FB70 @ =0x3FE57AFA
	ldr r3, _0823FB74 @ =0x7221858C
	bl FUN_0824d56c
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r2, _0823FB78 @ =0x40768000
	ldr r3, _0823FB7C @ =0x00000000
	ldr r0, [sp, #0xb0]
	ldr r1, [sp, #0xb4]
	bl FUN_0824d84c
	str r0, [sp, #0x80]
	str r1, [sp, #0x84]
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0x80]
	ldr r3, [sp, #0x84]
	bl FUN_0824d56c
	ldr r2, _0823FB80 @ =0x3FF00B36
	ldr r3, _0823FB84 @ =0xE7D9D4AE
	bl FUN_0824d84c
	ldr r4, _0823FB88 @ =0x40E38800
	ldr r5, _0823FB8C @ =0x00000000
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d53c
	mov r3, r8
	str r0, [r3]
	str r1, [r3, #4]
	ldr r2, [r3, #0x20]
	ldr r3, [r3, #0x24]
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	ldr r2, _0823FB70 @ =0x3FE57AFA
	ldr r3, _0823FB74 @ =0x7221858C
	bl FUN_0824d56c
	ldr r2, [sp, #0x80]
	ldr r3, [sp, #0x84]
	bl FUN_0824d56c
	ldr r2, _0823FB80 @ =0x3FF00B36
	ldr r3, _0823FB84 @ =0xE7D9D4AE
	bl FUN_0824d84c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d53c
	mov r2, r8
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	ldr r3, [r2, #0x2c]
	ldr r2, [r2, #0x28]
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d53c
	ldr r2, _0823FB70 @ =0x3FE57AFA
	ldr r3, _0823FB74 @ =0x7221858C
	bl FUN_0824d56c
	ldr r2, [sp, #0x80]
	ldr r3, [sp, #0x84]
	bl FUN_0824d56c
	ldr r2, _0823FB80 @ =0x3FF00B36
	ldr r3, _0823FB84 @ =0xE7D9D4AE
	bl FUN_0824d84c
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d53c
	mov r3, r8
	str r0, [r3, #0x10]
	str r1, [r3, #0x14]
	add sp, #0x90
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0823FB68: .4byte 0x3FF00000
_0823FB6C: .4byte 0x00000000
_0823FB70: .4byte 0x3FE57AFA
_0823FB74: .4byte 0x7221858C
_0823FB78: .4byte 0x40768000
_0823FB7C: .4byte 0x00000000
_0823FB80: .4byte 0x3FF00B36
_0823FB84: .4byte 0xE7D9D4AE
_0823FB88: .4byte 0x40E38800
_0823FB8C: .4byte 0x00000000

	thumb_func_start FUN_0823fb90
FUN_0823fb90: @ 0x0823FB90
	sub sp, #4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xac
	mov r8, r0
	mov sb, r1
	mov sl, r2
	str r3, [sp, #0xcc]
	ldr r3, _0823FDA0 @ =0x00000000
	ldr r2, _0823FD9C @ =0x40768000
	ldr r0, [sp, #0xd4]
	ldr r1, [sp, #0xd8]
	bl FUN_0824d84c
	str r0, [sp, #0x9c]
	str r1, [sp, #0xa0]
	add r0, sp, #0x14
	mov r1, r8
	mov r2, sb
	mov r3, sl
	bl FUN_0823e850
	ldr r4, _0823FDA4 @ =0x3FD80000
	ldr r5, _0823FDA8 @ =0x00000000
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d56c
	str r0, [sp, #0x44]
	str r1, [sp, #0x48]
	ldr r2, _0823FDAC @ =0x40E38800
	ldr r3, _0823FDB0 @ =0x00000000
	bl FUN_0824d56c
	ldr r2, _0823FDB4 @ =0x3FF00B36
	ldr r3, _0823FDB8 @ =0xE7D9D4AE
	bl FUN_0824d5a4
	ldr r2, _0823FDBC @ =0x3FE57AFA
	ldr r3, _0823FDC0 @ =0x7221858C
	bl FUN_0824d53c
	ldr r2, [sp, #0x9c]
	ldr r3, [sp, #0xa0]
	bl FUN_0824d53c
	str r0, [sp, #0x5c]
	str r1, [sp, #0x60]
	mov r3, sl
	adds r3, #1
	add r0, sp, #0x14
	mov r1, r8
	mov r2, sb
	bl FUN_0823e850
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d56c
	str r0, [sp, #0x4c]
	str r1, [sp, #0x50]
	ldr r2, _0823FDAC @ =0x40E38800
	ldr r3, _0823FDB0 @ =0x00000000
	bl FUN_0824d56c
	ldr r2, _0823FDB4 @ =0x3FF00B36
	ldr r3, _0823FDB8 @ =0xE7D9D4AE
	bl FUN_0824d5a4
	ldr r2, _0823FDBC @ =0x3FE57AFA
	ldr r3, _0823FDC0 @ =0x7221858C
	bl FUN_0824d53c
	ldr r2, [sp, #0x9c]
	ldr r3, [sp, #0xa0]
	bl FUN_0824d53c
	str r0, [sp, #0x64]
	str r1, [sp, #0x68]
	ldr r0, [sp, #0x44]
	ldr r1, [sp, #0x48]
	ldr r2, _0823FDC4 @ =0x3FE00000
	ldr r3, _0823FDC8 @ =0x00000000
	bl FUN_0824d53c
	adds r5, r1, #0
	adds r4, r0, #0
	str r4, [sp, #0x54]
	str r5, [sp, #0x58]
	ldr r2, _0823FDAC @ =0x40E38800
	ldr r3, _0823FDB0 @ =0x00000000
	bl FUN_0824d56c
	ldr r2, _0823FDB4 @ =0x3FF00B36
	ldr r3, _0823FDB8 @ =0xE7D9D4AE
	bl FUN_0824d5a4
	ldr r2, _0823FDBC @ =0x3FE57AFA
	ldr r3, _0823FDC0 @ =0x7221858C
	bl FUN_0824d53c
	ldr r2, [sp, #0x9c]
	ldr r3, [sp, #0xa0]
	bl FUN_0824d53c
	str r0, [sp, #0x6c]
	str r1, [sp, #0x70]
	movs r2, #0
	str r2, [sp, #0x74]
	str r2, [sp, #0x78]
	str r2, [sp, #0x7c]
	str r2, [sp, #0x80]
	bl FUN_0824dd44
	str r0, [sp]
	ldr r0, [sp, #0xd4]
	ldr r1, [sp, #0xd8]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [sp, #0xcc]
	ldr r1, [sp, #0xd0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r0, sp, #0x14
	movs r1, #1
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0823f618
	ldr r4, [sp, #0x1c]
	ldr r5, [sp, #0x20]
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823FDAC @ =0x40E38800
	ldr r3, _0823FDB0 @ =0x00000000
	bl FUN_0824d56c
	ldr r2, _0823FDB4 @ =0x3FF00B36
	ldr r3, _0823FDB8 @ =0xE7D9D4AE
	bl FUN_0824d5a4
	ldr r2, _0823FDBC @ =0x3FE57AFA
	ldr r3, _0823FDC0 @ =0x7221858C
	bl FUN_0824d53c
	ldr r2, [sp, #0x9c]
	ldr r3, [sp, #0xa0]
	bl FUN_0824d53c
	bl FUN_0824dd44
	str r0, [sp]
	ldr r0, [sp, #0xd4]
	ldr r1, [sp, #0xd8]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [sp, #0xcc]
	ldr r1, [sp, #0xd0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r0, sp, #0x14
	movs r1, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0823f618
	ldr r4, [sp, #0x14]
	ldr r5, [sp, #0x18]
	ldr r0, [sp, #0x24]
	ldr r1, [sp, #0x28]
	str r0, [sp, #0x84]
	str r1, [sp, #0x88]
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823FDAC @ =0x40E38800
	ldr r3, _0823FDB0 @ =0x00000000
	bl FUN_0824d56c
	ldr r2, _0823FDB4 @ =0x3FF00B36
	ldr r3, _0823FDB8 @ =0xE7D9D4AE
	bl FUN_0824d5a4
	ldr r2, _0823FDBC @ =0x3FE57AFA
	ldr r3, _0823FDC0 @ =0x7221858C
	bl FUN_0824d53c
	ldr r2, [sp, #0x9c]
	ldr r3, [sp, #0xa0]
	bl FUN_0824d53c
	bl FUN_0824dd44
	str r0, [sp]
	ldr r0, [sp, #0xd4]
	ldr r1, [sp, #0xd8]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [sp, #0xcc]
	ldr r1, [sp, #0xd0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r0, sp, #0x14
	movs r1, #1
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0823f618
	ldr r6, [sp, #0x14]
	ldr r7, [sp, #0x18]
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, _0823FDAC @ =0x40E38800
	ldr r3, _0823FDB0 @ =0x00000000
	bl FUN_0824d56c
	ldr r2, _0823FDB4 @ =0x3FF00B36
	ldr r3, _0823FDB8 @ =0xE7D9D4AE
	bl FUN_0824d5a4
	ldr r2, _0823FDBC @ =0x3FE57AFA
	ldr r3, _0823FDC0 @ =0x7221858C
	bl FUN_0824d53c
	ldr r2, [sp, #0x9c]
	ldr r3, [sp, #0xa0]
	bl FUN_0824d53c
	bl FUN_0824dd44
	str r0, [sp]
	ldr r0, [sp, #0xd4]
	ldr r1, [sp, #0xd8]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [sp, #0xcc]
	ldr r1, [sp, #0xd0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r0, sp, #0x14
	movs r1, #1
	adds r3, r7, #0
	adds r2, r6, #0
	bl FUN_0823f618
	ldr r4, [sp, #0x14]
	ldr r5, [sp, #0x18]
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824db98
	cmp r0, #0
	ble _0823FDCC
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	b _0823FDD4
	.align 2, 0
_0823FD9C: .4byte 0x40768000
_0823FDA0: .4byte 0x00000000
_0823FDA4: .4byte 0x3FD80000
_0823FDA8: .4byte 0x00000000
_0823FDAC: .4byte 0x40E38800
_0823FDB0: .4byte 0x00000000
_0823FDB4: .4byte 0x3FF00B36
_0823FDB8: .4byte 0xE7D9D4AE
_0823FDBC: .4byte 0x3FE57AFA
_0823FDC0: .4byte 0x7221858C
_0823FDC4: .4byte 0x3FE00000
_0823FDC8: .4byte 0x00000000
_0823FDCC:
	adds r1, r5, #0
	adds r0, r4, #0
	adds r3, r7, #0
	adds r2, r6, #0
_0823FDD4:
	bl FUN_0824d56c
	ldr r3, _0823FEBC @ =0x66666666
	ldr r2, _0823FEB8 @ =0x3FE66666
	bl FUN_0824db98
	str r4, [sp, #0x8c]
	str r5, [sp, #0x90]
	cmp r0, #0
	ble _0823FDF0
	ldr r0, _0823FEC0 @ =0xBFF00000
	ldr r1, _0823FEC4 @ =0x00000000
	str r0, [sp, #0x8c]
	str r1, [sp, #0x90]
_0823FDF0:
	ldr r0, [sp, #0x84]
	ldr r1, [sp, #0x88]
	ldr r2, _0823FEC8 @ =0x40E38800
	ldr r3, _0823FECC @ =0x00000000
	bl FUN_0824d56c
	ldr r2, _0823FED0 @ =0x3FF00B36
	ldr r3, _0823FED4 @ =0xE7D9D4AE
	bl FUN_0824d5a4
	ldr r2, _0823FED8 @ =0x3FE57AFA
	ldr r3, _0823FEDC @ =0x7221858C
	bl FUN_0824d53c
	adds r5, r1, #0
	adds r4, r0, #0
	ldr r2, _0823FEE0 @ =0x40768000
	ldr r3, _0823FEE4 @ =0x00000000
	ldr r0, [sp, #0xd4]
	ldr r1, [sp, #0xd8]
	bl FUN_0824d84c
	str r0, [sp, #0xa4]
	str r1, [sp, #0xa8]
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, [sp, #0xa4]
	ldr r3, [sp, #0xa8]
	bl FUN_0824d53c
	bl FUN_0824dd44
	str r0, [sp]
	ldr r0, [sp, #0xd4]
	ldr r1, [sp, #0xd8]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [sp, #0xcc]
	ldr r1, [sp, #0xd0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r0, sp, #0x14
	movs r1, #3
	ldr r2, [sp, #0x84]
	ldr r3, [sp, #0x88]
	bl FUN_0823f618
	ldr r6, [sp, #0x24]
	ldr r7, [sp, #0x28]
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, _0823FEC8 @ =0x40E38800
	ldr r3, _0823FECC @ =0x00000000
	bl FUN_0824d56c
	ldr r2, _0823FED0 @ =0x3FF00B36
	ldr r3, _0823FED4 @ =0xE7D9D4AE
	bl FUN_0824d5a4
	ldr r2, _0823FED8 @ =0x3FE57AFA
	ldr r3, _0823FEDC @ =0x7221858C
	bl FUN_0824d53c
	ldr r2, [sp, #0xa4]
	ldr r3, [sp, #0xa8]
	bl FUN_0824d53c
	bl FUN_0824dd44
	str r0, [sp]
	ldr r0, [sp, #0xd4]
	ldr r1, [sp, #0xd8]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [sp, #0xcc]
	ldr r1, [sp, #0xd0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r0, sp, #0x14
	movs r1, #3
	adds r3, r7, #0
	adds r2, r6, #0
	bl FUN_0823f618
	ldr r4, [sp, #0x24]
	ldr r5, [sp, #0x28]
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824db98
	cmp r0, #0
	ble _0823FEE8
	adds r1, r7, #0
	adds r0, r6, #0
	adds r3, r5, #0
	adds r2, r4, #0
	b _0823FEF0
	.align 2, 0
_0823FEB8: .4byte 0x3FE66666
_0823FEBC: .4byte 0x66666666
_0823FEC0: .4byte 0xBFF00000
_0823FEC4: .4byte 0x00000000
_0823FEC8: .4byte 0x40E38800
_0823FECC: .4byte 0x00000000
_0823FED0: .4byte 0x3FF00B36
_0823FED4: .4byte 0xE7D9D4AE
_0823FED8: .4byte 0x3FE57AFA
_0823FEDC: .4byte 0x7221858C
_0823FEE0: .4byte 0x40768000
_0823FEE4: .4byte 0x00000000
_0823FEE8:
	adds r1, r5, #0
	adds r0, r4, #0
	adds r3, r7, #0
	adds r2, r6, #0
_0823FEF0:
	bl FUN_0824d56c
	ldr r3, _0823FFE0 @ =0x66666666
	ldr r2, _0823FFDC @ =0x3FE66666
	bl FUN_0824db98
	str r4, [sp, #0x94]
	str r5, [sp, #0x98]
	cmp r0, #0
	ble _0823FF0C
	ldr r0, _0823FFE4 @ =0xBFF00000
	ldr r1, _0823FFE8 @ =0x00000000
	str r0, [sp, #0x94]
	str r1, [sp, #0x98]
_0823FF0C:
	ldr r0, [sp, #0x8c]
	ldr r1, [sp, #0x90]
	bl FUN_0824dd44
	bl FUN_0824dcc8
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x8c]
	ldr r1, [sp, #0x90]
	bl FUN_0824d56c
	ldr r2, _0823FFEC @ =0x3FD80000
	ldr r3, _0823FFF0 @ =0x00000000
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _0823FFF4 @ =0x3FF00000
	ldr r3, _0823FFF8 @ =0x00000000
	bl FUN_0824dbe4
	cmp r0, #0
	blt _0823FF4C
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, _0823FFF4 @ =0x3FF00000
	ldr r3, _0823FFF8 @ =0x00000000
	bl FUN_0824d56c
	adds r7, r1, #0
	adds r6, r0, #0
_0823FF4C:
	ldr r4, [sp, #0x44]
	ldr r5, [sp, #0x48]
	ldr r0, [sp, #0x8c]
	ldr r1, [sp, #0x90]
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824dbe4
	cmp r0, #0
	blt _0824003E
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _0823FFF4 @ =0x3FF00000
	ldr r3, _0823FFF8 @ =0x00000000
	bl FUN_0824d53c
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x8c]
	ldr r1, [sp, #0x90]
	bl FUN_0824dc30
	cmp r0, #0
	bge _0824003E
	ldr r2, _0823FFFC @ =0x40380000
	ldr r3, _08240000 @ =0x00000000
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d5a4
	adds r5, r1, #0
	adds r4, r0, #0
	bl FUN_0824dd44
	adds r6, r0, #0
	bl FUN_0824dcc8
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d56c
	ldr r2, _08240004 @ =0x404E0000
	ldr r3, _08240008 @ =0x00000000
	bl FUN_0824d5a4
	adds r5, r1, #0
	adds r4, r0, #0
	bl FUN_0824dd44
	adds r7, r0, #0
	bl FUN_0824dcc8
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d56c
	ldr r2, _0824000C @ =0x3FE00000
	ldr r3, _08240010 @ =0x00000000
	bl FUN_0824dc30
	cmp r0, #0
	bge _08240014
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824dd44
	adds r1, r7, #0
	b _08240016
	.align 2, 0
_0823FFDC: .4byte 0x3FE66666
_0823FFE0: .4byte 0x66666666
_0823FFE4: .4byte 0xBFF00000
_0823FFE8: .4byte 0x00000000
_0823FFEC: .4byte 0x3FD80000
_0823FFF0: .4byte 0x00000000
_0823FFF4: .4byte 0x3FF00000
_0823FFF8: .4byte 0x00000000
_0823FFFC: .4byte 0x40380000
_08240000: .4byte 0x00000000
_08240004: .4byte 0x404E0000
_08240008: .4byte 0x00000000
_0824000C: .4byte 0x3FE00000
_08240010: .4byte 0x00000000
_08240014:
	adds r1, r7, #1
_08240016:
	cmp r1, #0x3c
	bne _08240026
	movs r1, #0
	adds r6, #1
	cmp r6, #0x18
	bne _08240026
	movs r6, #0x17
	movs r1, #0x3b
_08240026:
	ldr r0, [sp, #0xdc]
	adds r6, r6, r0
	cmp r6, #0
	bge _08240032
	adds r6, #0x18
	b _08240038
_08240032:
	cmp r6, #0x17
	ble _08240038
	subs r6, #0x18
_08240038:
	adds r0, r6, #0
	bl FUN_0823de38
_0824003E:
	ldr r0, [sp, #0x94]
	ldr r1, [sp, #0x98]
	bl FUN_0824dd44
	bl FUN_0824dcc8
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x94]
	ldr r1, [sp, #0x98]
	bl FUN_0824d56c
	ldr r3, _08240114 @ =0x00000000
	ldr r2, _08240110 @ =0x3FD80000
	bl FUN_0824d53c
	adds r7, r1, #0
	adds r6, r0, #0
	ldr r2, _08240118 @ =0x3FF00000
	ldr r3, _0824011C @ =0x00000000
	bl FUN_0824dbe4
	cmp r0, #0
	blt _0824007E
	adds r1, r7, #0
	adds r0, r6, #0
	ldr r2, _08240118 @ =0x3FF00000
	ldr r3, _0824011C @ =0x00000000
	bl FUN_0824d56c
	adds r7, r1, #0
	adds r6, r0, #0
_0824007E:
	ldr r4, [sp, #0x44]
	ldr r5, [sp, #0x48]
	ldr r0, [sp, #0x94]
	ldr r1, [sp, #0x98]
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824dbe4
	cmp r0, #0
	blt _08240162
	adds r1, r5, #0
	adds r0, r4, #0
	ldr r2, _08240118 @ =0x3FF00000
	ldr r3, _0824011C @ =0x00000000
	bl FUN_0824d53c
	adds r3, r1, #0
	adds r2, r0, #0
	ldr r0, [sp, #0x94]
	ldr r1, [sp, #0x98]
	bl FUN_0824dc30
	cmp r0, #0
	bge _08240162
	ldr r2, _08240120 @ =0x40380000
	ldr r3, _08240124 @ =0x00000000
	adds r1, r7, #0
	adds r0, r6, #0
	bl FUN_0824d5a4
	adds r5, r1, #0
	adds r4, r0, #0
	bl FUN_0824dd44
	adds r6, r0, #0
	bl FUN_0824dcc8
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d56c
	ldr r2, _08240128 @ =0x404E0000
	ldr r3, _0824012C @ =0x00000000
	bl FUN_0824d5a4
	adds r5, r1, #0
	adds r4, r0, #0
	bl FUN_0824dd44
	adds r7, r0, #0
	bl FUN_0824dcc8
	adds r3, r1, #0
	adds r2, r0, #0
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824d56c
	ldr r2, _08240130 @ =0x3FE00000
	ldr r3, _08240134 @ =0x00000000
	bl FUN_0824dc30
	cmp r0, #0
	bge _08240138
	adds r1, r5, #0
	adds r0, r4, #0
	bl FUN_0824dd44
	adds r1, r7, #0
	b _0824013A
	.align 2, 0
_08240110: .4byte 0x3FD80000
_08240114: .4byte 0x00000000
_08240118: .4byte 0x3FF00000
_0824011C: .4byte 0x00000000
_08240120: .4byte 0x40380000
_08240124: .4byte 0x00000000
_08240128: .4byte 0x404E0000
_0824012C: .4byte 0x00000000
_08240130: .4byte 0x3FE00000
_08240134: .4byte 0x00000000
_08240138:
	adds r1, r7, #1
_0824013A:
	cmp r1, #0x3c
	bne _0824014A
	movs r1, #0
	adds r6, #1
	cmp r6, #0x18
	bne _0824014A
	movs r6, #0x17
	movs r1, #0x3b
_0824014A:
	ldr r0, [sp, #0xdc]
	adds r6, r6, r0
	cmp r6, #0
	bge _08240156
	adds r6, #0x18
	b _0824015C
_08240156:
	cmp r6, #0x17
	ble _0824015C
	subs r6, #0x18
_0824015C:
	adds r0, r6, #0
	bl FUN_0823df38
_08240162:
	add r0, sp, #0x14
	mov r1, r8
	mov r2, sb
	mov r3, sl
	bl FUN_0823f3e4
	ldr r3, _082401A0 @ =0x00000000
	ldr r2, _0824019C @ =0x40590000
	bl FUN_0824d5a4
	bl FUN_0824dd44
	adds r5, r0, #0
	movs r1, #0xa
	bl Mod
	adds r4, r0, #0
	cmp r4, #4
	ble _082401A4
	adds r0, r5, #0
	movs r1, #0x64
	bl Mod
	movs r1, #0xa
	bl Div
	adds r4, r0, #1
	b _082401B4
	.align 2, 0
_0824019C: .4byte 0x40590000
_082401A0: .4byte 0x00000000
_082401A4:
	adds r0, r5, #0
	movs r1, #0x64
	bl Mod
	movs r1, #0xa
	bl Div
	adds r4, r0, #0
_082401B4:
	cmp r4, #9
	ble _082401C6
	adds r0, r5, #0
	movs r1, #0x64
	bl Div
	adds r0, #1
	movs r4, #0
	b _082401CE
_082401C6:
	adds r0, r5, #0
	movs r1, #0x64
	bl Div
_082401CE:
	adds r1, r4, #0
	bl FUN_0823e470
	movs r0, #0
	add sp, #0xac
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r3}
	add sp, #4
	bx r3

	thumb_func_start FUN_082401e8
FUN_082401e8: @ 0x082401E8
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x24
	mov r8, r1
	mov sb, r2
	ldr r6, _08240258 @ =0x030047E0
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	str r2, [r6, #0x20]
	bl FUN_0824dcc8
	ldr r4, _0824025C @ =0x3EF00000
	ldr r5, _08240260 @ =0x00000000
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	str r0, [sp, #0x1c]
	str r1, [sp, #0x20]
	mov r0, r8
	bl FUN_0824dcc8
	adds r3, r5, #0
	adds r2, r4, #0
	bl FUN_0824d5a4
	adds r5, r1, #0
	adds r4, r0, #0
	add r1, sp, #0x14
	add r2, sp, #0x18
	ldr r3, [r6]
	add r0, sp, #0x10
	bl FUN_0823db08
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x18]
	str r4, [sp, #4]
	str r5, [sp, #8]
	mov r3, sb
	str r3, [sp, #0xc]
	ldr r3, [sp, #0x20]
	str r3, [sp]
	ldr r3, [sp, #0x1c]
	bl FUN_0823fb90
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08240258: .4byte 0x030047E0
_0824025C: .4byte 0x3EF00000
_08240260: .4byte 0x00000000

	thumb_func_start sound_08240264
sound_08240264: @ 0x08240264
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08240280 @ =0x0825E56C
	lsls r1, r5, #3
	adds r1, r1, r0
	ldrh r0, [r1, #4]
	cmp r0, #0xa
	bne _08240284
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStartOrContinue
	b _0824028C
	.align 2, 0
_08240280: .4byte 0x0825E56C
_08240284:
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStart
_0824028C:
	ldr r2, _082402B8 @ =0x0825E3EC
	ldr r1, _082402BC @ =0x0825E56C
	lsls r0, r5, #3
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	lsls r4, r0, #1
	adds r0, r4, r0
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ldr r1, _082402C0 @ =0x0000FFFF
	movs r2, #0x80
	lsls r2, r2, #1
	bl m4aMPlayVolumeControl
	ldr r0, _082402C4 @ =0x03004820
	adds r4, r4, r0
	strh r5, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_082402B8: .4byte 0x0825E3EC
_082402BC: .4byte 0x0825E56C
_082402C0: .4byte 0x0000FFFF
_082402C4: .4byte 0x03004820

	thumb_func_start FUN_082402c8
FUN_082402c8: @ 0x082402C8
	push {lr}
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _082402DC
	bl fetch_082316e4
	bl sound_08240264
_082402DC:
	pop {r0}
	bx r0

	thumb_func_start FUN_082402e0
FUN_082402e0: @ 0x082402E0
	push {lr}
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _082402F4
	bl fetch_082316e4
	bl sound_08240264
_082402F4:
	pop {r0}
	bx r0

	thumb_func_start sound_082402f8
sound_082402f8: @ 0x082402F8
	push {r4, r5, lr}
	adds r4, r0, #0
	cmp r4, #0
	beq _0824032C
	ldr r2, _08240324 @ =0x03004820
	ldr r1, _08240328 @ =0x0825E56C
	lsls r0, r4, #3
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	lsls r0, r0, #1
	adds r5, r0, r2
	ldrh r0, [r5]
	cmp r4, r0
	bne _0824033A
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStop
	movs r0, #0
	strh r0, [r5]
	b _0824033A
	.align 2, 0
_08240324: .4byte 0x03004820
_08240328: .4byte 0x0825E56C
_0824032C:
	ldr r5, _08240340 @ =0x03004820
	ldrh r0, [r5, #0x14]
	cmp r0, #0
	beq _0824033A
	bl m4aSongNumStop
	strh r4, [r5, #0x14]
_0824033A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08240340: .4byte 0x03004820

	thumb_func_start sound_08240344
sound_08240344: @ 0x08240344
	push {lr}
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _08240356
	bl fetch_082316e4
	b _08240358
_08240356:
	movs r0, #0
_08240358:
	bl sound_082402f8
	pop {r0}
	bx r0

	thumb_func_start FUN_08240360
FUN_08240360: @ 0x08240360
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r1, _082403A8 @ =0x03004820
	ldrh r0, [r1, #0x14]
	cmp r0, #0
	beq _082403A2
	adds r5, r0, #0
	ldr r1, _082403AC @ =0x0825E56C
	lsls r0, r5, #3
	adds r0, r0, r1
	ldrh r1, [r0, #4]
	ldr r2, _082403B0 @ =0x0825E3EC
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r4, [r0]
	adds r0, r4, #0
	bl m4aMPlayImmInit
	ldr r1, _082403B4 @ =0x0000FFFF
	adds r0, r4, #0
	movs r2, #1
	bl m4aMPlayVolumeControl
	adds r0, r5, #0
	bl m4aSongNumStop
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl m4aMPlayFadeIn
_082403A2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_082403A8: .4byte 0x03004820
_082403AC: .4byte 0x0825E56C
_082403B0: .4byte 0x0825E3EC
_082403B4: .4byte 0x0000FFFF

	thumb_func_start sound_082403b8
sound_082403b8: @ 0x082403B8
	push {lr}
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _082403CC
	bl fetch_082316e4
	bl FUN_08240360
_082403CC:
	pop {r0}
	bx r0

	thumb_func_start FUN_082403d0
FUN_082403d0: @ 0x082403D0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r6, _08240418 @ =0x03004820
	ldrh r0, [r6, #0x14]
	cmp r0, #0
	beq _08240412
	ldr r1, _0824041C @ =0x0825E56C
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	ldr r1, _08240420 @ =0x0825E3EC
	lsls r5, r0, #1
	adds r0, r5, r0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r4, #0
	bl m4aMPlayImmInit
	ldr r1, _08240424 @ =0x0000FFFF
	movs r2, #0x80
	lsls r2, r2, #1
	adds r0, r4, #0
	bl m4aMPlayVolumeControl
	lsls r1, r7, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl m4aMPlayFadeOutTemporarily
	adds r5, r5, r6
	movs r0, #0
	strh r0, [r5]
_08240412:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08240418: .4byte 0x03004820
_0824041C: .4byte 0x0825E56C
_08240420: .4byte 0x0825E3EC
_08240424: .4byte 0x0000FFFF

	thumb_func_start FUN_08240428
FUN_08240428: @ 0x08240428
	push {lr}
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0824043C
	bl fetch_082316e4
	bl FUN_082403d0
_0824043C:
	pop {r0}
	bx r0

	thumb_func_start FUN_08240440
FUN_08240440: @ 0x08240440
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r6, _08240488 @ =0x03004820
	ldrh r0, [r6, #0x14]
	cmp r0, #0
	beq _08240480
	ldr r1, _0824048C @ =0x0825E56C
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	ldr r1, _08240490 @ =0x0825E3EC
	lsls r5, r0, #1
	adds r0, r5, r0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r4, #0
	bl m4aMPlayImmInit
	ldr r1, _08240494 @ =0x0000FFFF
	adds r0, r4, #0
	movs r2, #0xff
	bl m4aMPlayVolumeControl
	lsls r1, r7, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl m4aMPlayFadeOut
	adds r5, r5, r6
	movs r0, #0
	strh r0, [r5]
_08240480:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08240488: .4byte 0x03004820
_0824048C: .4byte 0x0825E56C
_08240490: .4byte 0x0825E3EC
_08240494: .4byte 0x0000FFFF

	thumb_func_start FUN_08240498
FUN_08240498: @ 0x08240498
	push {lr}
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _082404AC
	bl fetch_082316e4
	bl FUN_08240440
_082404AC:
	pop {r0}
	bx r0

	thumb_func_start FUN_082404b0
FUN_082404b0: @ 0x082404B0
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _082404EC @ =0x0825E56C
	lsls r1, r5, #3
	adds r4, r1, r0
	ldrh r0, [r4, #4]
	cmp r0, #0xc
	bne _082404E6
	lsls r0, r5, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStartOrContinue
	ldr r1, _082404F0 @ =0x0825E3EC
	ldrh r0, [r4, #4]
	lsls r4, r0, #1
	adds r0, r4, r0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r1, _082404F4 @ =0x0000FFFF
	movs r2, #0x80
	lsls r2, r2, #1
	bl m4aMPlayVolumeControl
	ldr r0, _082404F8 @ =0x03004820
	adds r4, r4, r0
	strh r5, [r4]
_082404E6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_082404EC: .4byte 0x0825E56C
_082404F0: .4byte 0x0825E3EC
_082404F4: .4byte 0x0000FFFF
_082404F8: .4byte 0x03004820

	thumb_func_start FUN_082404fc
FUN_082404fc: @ 0x082404FC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08240540 @ =0x03004820
	ldrh r5, [r0, #0x18]
	cmp r5, #0
	beq _0824053A
	ldr r0, _08240544 @ =0x0825E56C
	lsls r1, r5, #3
	adds r1, r1, r0
	ldrh r0, [r1, #4]
	cmp r0, #0xc
	bne _0824053A
	ldr r0, _08240548 @ =0x0825E3EC
	adds r0, #0x90
	ldr r4, [r0]
	adds r0, r4, #0
	bl m4aMPlayImmInit
	ldr r1, _0824054C @ =0x0000FFFF
	adds r0, r4, #0
	movs r2, #1
	bl m4aMPlayVolumeControl
	adds r0, r5, #0
	bl m4aSongNumStop
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl m4aMPlayFadeIn
_0824053A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08240540: .4byte 0x03004820
_08240544: .4byte 0x0825E56C
_08240548: .4byte 0x0825E3EC
_0824054C: .4byte 0x0000FFFF

	thumb_func_start FUN_08240550
FUN_08240550: @ 0x08240550
	push {lr}
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _08240564
	bl fetch_082316e4
	bl FUN_082404fc
_08240564:
	pop {r0}
	bx r0

	thumb_func_start FUN_08240568
FUN_08240568: @ 0x08240568
	push {r4, r5, lr}
	adds r2, r0, #0
	ldr r5, _0824059C @ =0x03004820
	ldrh r0, [r5, #0x18]
	cmp r0, #0
	beq _08240596
	ldr r1, _082405A0 @ =0x0825E56C
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	ldr r1, _082405A4 @ =0x0825E3EC
	lsls r4, r0, #1
	adds r0, r4, r0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	lsls r1, r2, #0x10
	lsrs r1, r1, #0x10
	bl m4aMPlayFadeOutTemporarily
	adds r4, r4, r5
	movs r0, #0
	strh r0, [r4]
_08240596:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0824059C: .4byte 0x03004820
_082405A0: .4byte 0x0825E56C
_082405A4: .4byte 0x0825E3EC

	thumb_func_start FUN_082405a8
FUN_082405a8: @ 0x082405A8
	push {lr}
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _082405BC
	bl fetch_082316e4
	bl FUN_08240568
_082405BC:
	pop {r0}
	bx r0

	thumb_func_start FUN_082405c0
FUN_082405c0: @ 0x082405C0
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r7, _08240608 @ =0x03004820
	ldrh r0, [r7, #0x18]
	cmp r0, #0
	beq _08240600
	ldr r1, _0824060C @ =0x0825E56C
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	ldr r1, _08240610 @ =0x0825E3EC
	lsls r5, r0, #1
	adds r0, r5, r0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r4, [r0]
	adds r0, r4, #0
	bl m4aMPlayImmInit
	ldr r1, _08240614 @ =0x0000FFFF
	adds r0, r4, #0
	movs r2, #0xff
	bl m4aMPlayVolumeControl
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl m4aMPlayFadeOut
	adds r5, r5, r7
	movs r0, #0
	strh r0, [r5]
_08240600:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08240608: .4byte 0x03004820
_0824060C: .4byte 0x0825E56C
_08240610: .4byte 0x0825E3EC
_08240614: .4byte 0x0000FFFF

	thumb_func_start FUN_08240618
FUN_08240618: @ 0x08240618
	push {lr}
	movs r0, #0x66
	bl prepare_08231510
	cmp r0, #0
	beq _0824062C
	bl fetch_082316e4
	bl FUN_082405c0
_0824062C:
	pop {r0}
	bx r0

	thumb_func_start FUN_08240630
FUN_08240630: @ 0x08240630
	push {lr}
	adds r3, r0, #0
	ldr r0, _0824065C @ =0x03004820
	ldrh r0, [r0, #0x14]
	cmp r0, #0
	beq _08240658
	ldr r1, _08240660 @ =0x0825E56C
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r1, [r0, #4]
	ldr r2, _08240664 @ =0x0825E3EC
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r3, #0x10
	lsrs r1, r1, #0x10
	bl m4aMPlayTempoControl
_08240658:
	pop {r0}
	bx r0
	.align 2, 0
_0824065C: .4byte 0x03004820
_08240660: .4byte 0x0825E56C
_08240664: .4byte 0x0825E3EC

	thumb_func_start FUN_08240668
FUN_08240668: @ 0x08240668
	push {lr}
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _0824067C
	bl fetch_082316e4
	bl FUN_08240630
_0824067C:
	pop {r0}
	bx r0

	thumb_func_start FUN_08240680
FUN_08240680: @ 0x08240680
	push {r4, lr}
	movs r0, #0x76
	bl prepare_08231510
	cmp r0, #0
	beq _082406CE
	bl fetch_082316e4
	adds r4, r0, #0
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _082406A4
	bl fetch_082316e4
	adds r3, r0, #0
	b _082406A6
_082406A4:
	movs r3, #0xff
_082406A6:
	ldr r0, _082406D4 @ =0x03004820
	ldrh r0, [r0, #0x14]
	cmp r0, #0
	beq _082406CE
	ldr r1, _082406D8 @ =0x0825E56C
	lsls r0, r0, #3
	adds r0, r0, r1
	ldrh r1, [r0, #4]
	ldr r2, _082406DC @ =0x0825E3EC
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r2
	ldr r0, [r0]
	lsls r1, r3, #0x10
	lsrs r1, r1, #0x10
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	bl m4aMPlayVolumeControl
_082406CE:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082406D4: .4byte 0x03004820
_082406D8: .4byte 0x0825E56C
_082406DC: .4byte 0x0825E3EC

	thumb_func_start PlaySound_082406e0
PlaySound_082406e0: @ 0x082406E0
	push {lr}
	adds r3, r0, #0
	ldr r0, _0824070C @ =0x030044BC
	ldr r0, [r0]
	movs r1, #6
	ands r0, r1
	cmp r0, #0
	bne _08240700
	ldr r2, _08240710 @ =0x03004820
	ldr r1, _08240714 @ =0x0825E56C
	lsls r0, r3, #3
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	lsls r0, r0, #1
	adds r0, r0, r2
	strh r3, [r0]
_08240700:
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStart
	pop {r0}
	bx r0
	.align 2, 0
_0824070C: .4byte 0x030044BC
_08240710: .4byte 0x03004820
_08240714: .4byte 0x0825E56C

	thumb_func_start PlaySound_08240718
PlaySound_08240718: @ 0x08240718
	push {lr}
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStart
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sound_08240728
sound_08240728: @ 0x08240728
	push {lr}
	movs r0, #0x69
	bl prepare_08231510
	cmp r0, #0
	beq _0824073C
	bl fetch_082316e4
	bl PlaySound_08240718
_0824073C:
	pop {r0}
	bx r0

	thumb_func_start sound_08240740
sound_08240740: @ 0x08240740
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0824075C @ =0x030044BC
	ldr r3, [r0]
	movs r0, #6
	ands r3, r0
	cmp r3, #0
	beq _08240760
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStop
	b _0824077E
	.align 2, 0
_0824075C: .4byte 0x030044BC
_08240760:
	ldr r2, _08240784 @ =0x03004820
	ldr r1, _08240788 @ =0x0825E56C
	lsls r0, r4, #3
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	lsls r0, r0, #1
	adds r0, r0, r2
	ldrh r1, [r0]
	cmp r4, r1
	bne _0824077E
	strh r3, [r0]
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	bl m4aSongNumStop
_0824077E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08240784: .4byte 0x03004820
_08240788: .4byte 0x0825E56C

	thumb_func_start FUN_0824078c
FUN_0824078c: @ 0x0824078C
	push {lr}
	adds r3, r0, #0
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _082407B0 @ =0x030047A4
	ldr r1, _082407B4 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _082407AA
	adds r0, r3, #0
	bl PlaySound_082406e0
_082407AA:
	pop {r0}
	bx r0
	.align 2, 0
_082407B0: .4byte 0x030047A4
_082407B4: .4byte 0x030047A0

	thumb_func_start FUN_082407b8
FUN_082407b8: @ 0x082407B8
	push {r4, r5, lr}
	ldr r4, _082407DC @ =0x03004820
	movs r5, #0x1f
_082407BE:
	ldrh r0, [r4]
	cmp r0, #0
	beq _082407CC
	bl m4aSongNumStop
	movs r0, #0
	strh r0, [r4]
_082407CC:
	adds r4, #2
	subs r5, #1
	cmp r5, #0
	bge _082407BE
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_082407DC: .4byte 0x03004820

	thumb_func_start FUN_082407e0
FUN_082407e0: @ 0x082407E0
	push {r4, r5, r6, lr}
	movs r1, #0
	ldr r6, _08240800 @ =0x0825E3EC
	ldr r2, _08240804 @ =0x03004820
	adds r5, r2, #0
	ldr r4, _08240808 @ =0x0000FFFF
	movs r3, #0
_082407EE:
	cmp r1, #0xa
	bne _0824080C
	ldr r0, [r6, #0x78]
	ldr r0, [r0, #4]
	ands r0, r4
	cmp r0, #0
	bne _0824081A
	strh r0, [r5, #0x14]
	b _0824081A
	.align 2, 0
_08240800: .4byte 0x0825E3EC
_08240804: .4byte 0x03004820
_08240808: .4byte 0x0000FFFF
_0824080C:
	cmp r1, #0xc
	beq _0824081A
	cmp r1, #0x1d
	beq _0824081A
	cmp r1, #0x1e
	beq _0824081A
	strh r3, [r2]
_0824081A:
	adds r2, #2
	adds r1, #1
	cmp r1, #0x1f
	ble _082407EE
	bl m4aMPlayAllStop
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0824082c
FUN_0824082c: @ 0x0824082C
	push {r4, r5, r6, lr}
	ldr r5, _0824084C @ =0x03004820
	adds r6, r5, #0
	adds r4, r5, #0
_08240834:
	ldrh r0, [r4]
	cmp r0, #0
	beq _0824086A
	adds r0, r5, #0
	adds r0, #0x14
	cmp r4, r0
	bne _08240850
	ldrh r0, [r5, #0x14]
	bl m4aSongNumStartOrContinue
	b _0824086A
	.align 2, 0
_0824084C: .4byte 0x03004820
_08240850:
	adds r0, r5, #0
	adds r0, #0x18
	cmp r4, r0
	beq _08240864
	adds r0, #0x22
	cmp r4, r0
	beq _08240864
	adds r0, #2
	cmp r4, r0
	bne _0824086A
_08240864:
	ldrh r0, [r6]
	bl m4aSongNumStartOrChange
_0824086A:
	adds r6, #2
	adds r4, #2
	adds r0, r5, #0
	adds r0, #0x3e
	cmp r4, r0
	ble _08240834
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0824087c
FUN_0824087c: @ 0x0824087C
	push {lr}
	bl FUN_0824082c
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08240888
FUN_08240888: @ 0x08240888
	push {r4, r5, r6, lr}
	movs r5, #0
	ldr r6, _082408B0 @ =0x0825E3EC
_0824088E:
	lsls r4, r5, #1
	ldr r0, [r6]
	bl m4aMPlayStop
	ldr r0, _082408B4 @ =0x03004820
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	adds r6, #0xc
	adds r5, #1
	cmp r5, #0x1f
	ble _0824088E
	bl m4aSoundInit
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_082408B0: .4byte 0x0825E3EC
_082408B4: .4byte 0x03004820

	thumb_func_start FUN_082408b8
FUN_082408b8: @ 0x082408B8
	push {lr}
	ldr r1, _082408CC @ =0x03004820
	ldrh r0, [r1, #0x3c]
	cmp r0, #0
	beq _082408C6
	bl sound_08240740
_082408C6:
	pop {r0}
	bx r0
	.align 2, 0
_082408CC: .4byte 0x03004820

	thumb_func_start FUN_082408d0
FUN_082408d0: @ 0x082408D0
	push {r4, lr}
	ldr r4, _082408F0 @ =0x03004820
	ldrh r0, [r4, #0x3a]
	cmp r0, #0
	beq _082408DE
	bl m4aSongNumStop
_082408DE:
	ldrh r0, [r4, #0x3c]
	cmp r0, #0
	beq _082408E8
	bl m4aSongNumStop
_082408E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_082408F0: .4byte 0x03004820

	thumb_func_start FUN_082408f4
FUN_082408f4: @ 0x082408F4
	push {r4, lr}
	ldr r4, _08240914 @ =0x03004820
	ldrh r0, [r4, #0x3a]
	cmp r0, #0
	beq _08240902
	bl m4aSongNumStart
_08240902:
	ldrh r0, [r4, #0x3c]
	cmp r0, #0
	beq _0824090C
	bl m4aSongNumStart
_0824090C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08240914: .4byte 0x03004820

	thumb_func_start FUN_08240918
FUN_08240918: @ 0x08240918
	push {lr}
	ldr r1, _0824092C @ =0x03004820
	ldrh r0, [r1, #0x3c]
	cmp r0, #0
	beq _08240926
	bl m4aSongNumStop
_08240926:
	pop {r0}
	bx r0
	.align 2, 0
_0824092C: .4byte 0x03004820

	thumb_func_start FUN_08240930
FUN_08240930: @ 0x08240930
	push {lr}
	ldr r1, _08240944 @ =0x03004820
	ldrh r0, [r1, #0x3c]
	cmp r0, #0
	beq _0824093E
	bl m4aSongNumStart
_0824093E:
	pop {r0}
	bx r0
	.align 2, 0
_08240944: .4byte 0x03004820

	thumb_func_start FUN_08240948
FUN_08240948: @ 0x08240948
	push {lr}
	bl m4aSoundVSyncOff
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08240954
FUN_08240954: @ 0x08240954
	push {lr}
	bl m4aSoundVSyncOn
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start sound_08240960
sound_08240960: @ 0x08240960
	push {lr}
	adds r3, r0, #0
	ldr r1, _0824098C @ =0x0825E56C
	lsls r0, r3, #3
	adds r0, r0, r1
	ldrh r0, [r0, #4]
	ldr r1, _08240990 @ =0x0825E3EC
	lsls r2, r0, #1
	adds r0, r2, r0
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	ldr r0, [r0, #4]
	cmp r0, #0
	blt _08240998
	ldr r0, _08240994 @ =0x03004820
	adds r0, r2, r0
	ldrh r0, [r0]
	cmp r0, r3
	bne _08240998
	movs r0, #1
	b _0824099A
	.align 2, 0
_0824098C: .4byte 0x0825E56C
_08240990: .4byte 0x0825E3EC
_08240994: .4byte 0x03004820
_08240998:
	movs r0, #0
_0824099A:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082409a0
FUN_082409a0: @ 0x082409A0
	push {r4, lr}
	adds r3, r0, #0
	movs r2, #0
	ldr r4, _082409BC @ =0x030016FC
_082409A8:
	ldr r0, [r4]
	lsls r1, r2, #1
	adds r0, #2
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, #0
	bne _082409C0
	strh r3, [r1]
	movs r0, #1
	b _082409C8
	.align 2, 0
_082409BC: .4byte 0x030016FC
_082409C0:
	adds r2, #1
	cmp r2, #3
	ble _082409A8
	movs r0, #0
_082409C8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082409d0
FUN_082409d0: @ 0x082409D0
	push {r4, r5, lr}
	adds r3, r0, #0
	movs r2, #0
	ldr r4, _082409F0 @ =0x030016FC
	movs r5, #0
_082409DA:
	ldr r0, [r4]
	lsls r1, r2, #1
	adds r0, #2
	adds r1, r0, r1
	ldrh r0, [r1]
	cmp r0, r3
	bne _082409F4
	strh r5, [r1]
	movs r0, #1
	b _082409FC
	.align 2, 0
_082409F0: .4byte 0x030016FC
_082409F4:
	adds r2, #1
	cmp r2, #3
	ble _082409DA
	movs r0, #0
_082409FC:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08240a04
FUN_08240a04: @ 0x08240A04
	movs r0, #0
	bx lr

	thumb_func_start FUN_08240a08
FUN_08240a08: @ 0x08240A08
	push {r4, lr}
	ldr r4, _08240A1C @ =0x030016FC
	ldr r0, [r4]
	bl FUN_0823092c
	movs r0, #0
	str r0, [r4]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08240A1C: .4byte 0x030016FC

	thumb_func_start FUN_08240a20
FUN_08240a20: @ 0x08240A20
	push {r4, lr}
	ldr r1, _08240A30 @ =0x030016FC
	ldr r0, [r1]
	cmp r0, #0
	bne _08240A34
	movs r0, #1
	rsbs r0, r0, #0
	b _08240A4C
	.align 2, 0
_08240A30: .4byte 0x030016FC
_08240A34:
	movs r2, #0
	adds r4, r1, #0
	movs r3, #0
_08240A3A:
	ldr r0, [r4]
	lsls r1, r2, #1
	adds r0, #2
	adds r0, r0, r1
	strh r3, [r0]
	adds r2, #1
	cmp r2, #3
	ble _08240A3A
	movs r0, #0
_08240A4C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08240a54
FUN_08240a54: @ 0x08240A54
	push {r4, lr}
	movs r0, #3
	movs r1, #0x18
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08240A88
	ldr r1, _08240A80 @ =FUN_08240a04
	ldr r2, _08240A84 @ =FUN_08240a08
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_08240a20
	cmp r0, #0
	bge _08240A88
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08240A8A
	.align 2, 0
_08240A80: .4byte FUN_08240a04
_08240A84: .4byte FUN_08240a08
_08240A88:
	adds r0, r4, #0
_08240A8A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08240a90
FUN_08240a90: @ 0x08240A90
	push {r4, r5, lr}
	ldr r5, _08240AC4 @ =0x0000757B
	adds r0, r5, #0
	bl FUN_08230e70
	cmp r0, #0
	bne _08240ACC
	movs r0, #0xc
	bl AllocateEntity
	adds r4, r0, #0
	movs r1, #0xc
	bl FUN_082309cc
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_08230e30
	ldr r0, _08240AC8 @ =0x030016FC
	str r4, [r0]
	bl FUN_08240a54
	movs r0, #1
	b _08240ACE
	.align 2, 0
_08240AC4: .4byte 0x0000757B
_08240AC8: .4byte 0x030016FC
_08240ACC:
	movs r0, #0
_08240ACE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08240ad4
FUN_08240ad4: @ 0x08240AD4
	push {lr}
	subs r3, r0, r3
	cmp r3, #0
	bge _08240ADE
	rsbs r3, r3, #0
_08240ADE:
	ldr r0, [sp, #4]
	subs r1, r1, r0
	cmp r1, #0
	bge _08240AE8
	rsbs r1, r1, #0
_08240AE8:
	ldr r0, [sp, #8]
	adds r2, r2, r0
	cmp r3, r2
	bge _08240AF8
	cmp r1, r2
	bge _08240AF8
	movs r0, #1
	b _08240AFA
_08240AF8:
	movs r0, #0
_08240AFA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08240b00
FUN_08240b00: @ 0x08240B00
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08240B10 @ =0x03001700
	ldr r0, [r0]
	cmp r0, #0
	bne _08240B18
	b _08240B3C
	.align 2, 0
_08240B10: .4byte 0x03001700
_08240B14:
	movs r0, #1
	b _08240B3E
_08240B18:
	movs r5, #0
	adds r4, r0, #0
	adds r4, #0x98
_08240B1E:
	ldr r0, [r4]
	cmp r0, #0
	ble _08240B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0
	bl FUN_08234d50
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08240B14
_08240B34:
	adds r4, #4
	adds r5, #1
	cmp r5, #0xf
	ble _08240B1E
_08240B3C:
	movs r0, #0
_08240B3E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08240b44
FUN_08240b44: @ 0x08240B44
	push {r4, r5, r6, r7, lr}
	ldr r0, _08240B74 @ =0x03001700
	ldr r0, [r0]
	cmp r0, #0
	beq _08240B90
	movs r7, #4
	ldr r6, _08240B78 @ =0x0000FFFB
	adds r1, r0, #0
	adds r1, #0x20
	ldr r0, _08240B7C @ =0x0000FFFF
	adds r5, r0, #0
	movs r4, #7
_08240B5C:
	ldrh r2, [r1, #4]
	adds r0, r7, #0
	ands r0, r2
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0
	beq _08240B80
	adds r0, r6, #0
	ands r0, r2
	strh r0, [r1, #4]
	b _08240B88
	.align 2, 0
_08240B74: .4byte 0x03001700
_08240B78: .4byte 0x0000FFFB
_08240B7C: .4byte 0x0000FFFF
_08240B80:
	ldrh r0, [r1]
	orrs r0, r5
	strh r0, [r1]
	strh r3, [r1, #4]
_08240B88:
	adds r1, #0x10
	subs r4, #1
	cmp r4, #0
	bge _08240B5C
_08240B90:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08240b98
FUN_08240b98: @ 0x08240B98
	push {lr}
	adds r3, r0, #0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldr r0, _08240BC0 @ =0x03001700
	ldr r2, [r0]
	cmp r2, #0
	beq _08240BC4
	lsls r0, r1, #0x18
	asrs r0, r0, #0x14
	adds r0, r2, r0
	ldrh r1, [r0, #0x18]
	movs r2, #0
	strh r1, [r3]
	strh r2, [r3, #2]
	ldrh r1, [r0, #0x1c]
	strh r1, [r3, #4]
	ldrh r0, [r0, #0x26]
	b _08240BC6
	.align 2, 0
_08240BC0: .4byte 0x03001700
_08240BC4:
	movs r0, #0
_08240BC6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08240bcc
FUN_08240bcc: @ 0x08240BCC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	ldr r4, [sp, #0x2c]
	ldr r5, [sp, #0x30]
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r8, r2
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp, #8]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	mov sl, r5
	ldr r0, _08240C58 @ =0x03001700
	ldr r5, [r0]
	cmp r5, #0
	beq _08240C8A
	ldr r0, _08240C5C @ =0xFFFF0000
	str r6, [sp]
	ldr r1, [sp, #4]
	ands r1, r0
	orrs r1, r7
	str r1, [sp, #4]
	mov r0, sp
	bl FUN_08240b00
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08240C8A
	movs r2, #0
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r0, r0, #0xf
	mov sb, r0
	movs r0, #4
	orrs r4, r0
	ldr r0, _08240C60 @ =0x030046A0
	mov ip, r0
	adds r1, r5, #0
	movs r3, #0
_08240C30:
	movs r5, #0x20
	ldrsh r0, [r1, r5]
	cmp r0, #0
	bge _08240C82
	strh r6, [r1, #0x18]
	strh r3, [r1, #0x1a]
	strh r7, [r1, #0x1c]
	mov r0, sl
	strh r0, [r1, #0x26]
	mov r2, ip
	ldr r0, [r2]
	ldr r5, _08240C64 @ =0x00000934
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #0x80
	ands r0, r2
	cmp r0, #0
	beq _08240C68
	movs r0, #1
	b _08240C6A
	.align 2, 0
_08240C58: .4byte 0x03001700
_08240C5C: .4byte 0xFFFF0000
_08240C60: .4byte 0x030046A0
_08240C64: .4byte 0x00000934
_08240C68:
	movs r0, #0
_08240C6A:
	cmp r0, #0
	beq _08240C74
	mov r5, sb
	strh r5, [r1, #0x20]
	b _08240C78
_08240C74:
	mov r0, r8
	strh r0, [r1, #0x20]
_08240C78:
	mov r2, sp
	ldrh r2, [r2, #8]
	strh r2, [r1, #0x22]
	strh r4, [r1, #0x24]
	b _08240C8A
_08240C82:
	adds r1, #0x10
	adds r2, #1
	cmp r2, #7
	ble _08240C30
_08240C8A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08240c9c
FUN_08240c9c: @ 0x08240C9C
	push {r4, lr}
	sub sp, #8
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	movs r4, #1
	str r4, [sp]
	movs r4, #0
	str r4, [sp, #4]
	bl FUN_08240bcc
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08240cc4
FUN_08240cc4: @ 0x08240CC4
	push {r4, lr}
	sub sp, #8
	ldr r4, [sp, #0x10]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	str r4, [sp]
	movs r4, #0
	str r4, [sp, #4]
	bl FUN_08240bcc
	add sp, #8
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08240cf0
FUN_08240cf0: @ 0x08240CF0
	push {r4, r5, lr}
	sub sp, #8
	ldr r4, [sp, #0x14]
	ldr r5, [sp, #0x18]
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	lsls r3, r3, #0x10
	asrs r3, r3, #0x10
	str r4, [sp]
	str r5, [sp, #4]
	bl FUN_08240bcc
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08240d20
FUN_08240d20: @ 0x08240D20
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sl, r0
	mov sb, r1
	mov r8, r2
	ldr r0, [sp, #0x28]
	lsls r3, r3, #0x18
	lsrs r7, r3, #0x18
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, _08240D48 @ =0x03001700
	ldr r1, [r0]
	cmp r1, #0
	bne _08240D52
	b _08240DB2
	.align 2, 0
_08240D48: .4byte 0x03001700
_08240D4C:
	lsls r0, r5, #0x18
	asrs r0, r0, #0x18
	b _08240DB6
_08240D52:
	ldr r5, [sp, #0x2c]
	cmp r5, #7
	bgt _08240DB2
	lsls r0, r5, #4
	adds r0, #0x18
	adds r4, r0, r1
_08240D5E:
	ldrh r1, [r4, #0xc]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	bne _08240DAA
	ldrh r0, [r4, #0xe]
	cmp r0, #0
	beq _08240D72
	cmp r0, r6
	beq _08240DAA
_08240D72:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	bne _08240D4C
	movs r1, #8
	ldrsh r0, [r4, r1]
	cmp r0, #0
	blt _08240DAA
	ldrh r0, [r4, #0xc]
	ands r0, r7
	cmp r0, #0
	beq _08240DAA
	movs r2, #0
	ldrsh r0, [r4, r2]
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r3, #8
	ldrsh r2, [r4, r3]
	mov r3, sb
	str r3, [sp]
	mov r3, r8
	str r3, [sp, #4]
	mov r3, sl
	bl FUN_08240ad4
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08240D4C
_08240DAA:
	adds r4, #0x10
	adds r5, #1
	cmp r5, #7
	ble _08240D5E
_08240DB2:
	movs r0, #1
	rsbs r0, r0, #0
_08240DB6:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08240dc8
FUN_08240dc8: @ 0x08240DC8
	push {r4, lr}
	sub sp, #8
	ldr r4, [sp, #0x10]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp]
	movs r4, #0
	str r4, [sp, #4]
	bl FUN_08240d20
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08240dec
FUN_08240dec: @ 0x08240DEC
	push {r4, r5, lr}
	sub sp, #8
	ldr r4, [sp, #0x14]
	ldr r5, [sp, #0x18]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp]
	str r5, [sp, #4]
	bl FUN_08240d20
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08240e10
FUN_08240e10: @ 0x08240E10
	push {lr}
	bl FUN_08240b44
	movs r0, #1
	pop {r1}
	bx r1

	thumb_func_start FUN_08240e1c
FUN_08240e1c: @ 0x08240E1C
	ldr r2, _08240E24 @ =0x03001700
	movs r1, #0
	str r1, [r2]
	bx lr
	.align 2, 0
_08240E24: .4byte 0x03001700

	thumb_func_start FUN_08240e28
FUN_08240e28: @ 0x08240E28
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _08240E4A
	adds r4, r5, #0
	adds r4, #0x98
	b _08240E42
_08240E3C:
	bl fetch_082316e4
	stm r4!, {r0}
_08240E42:
	bl FUN_082316bc
	cmp r0, #0
	bne _08240E3C
_08240E4A:
	bl FUN_08240b44
	ldr r0, _08240E5C @ =0x03001700
	str r5, [r0]
	movs r0, #1
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08240E5C: .4byte 0x03001700

	thumb_func_start FUN_08240e60
FUN_08240e60: @ 0x08240E60
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #5
	movs r1, #0xd8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08240E9C
	ldr r1, _08240E94 @ =FUN_08240e10
	ldr r2, _08240E98 @ =FUN_08240e1c
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_08240e28
	cmp r0, #0
	bge _08240E9C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08240E9E
	.align 2, 0
_08240E94: .4byte FUN_08240e10
_08240E98: .4byte FUN_08240e1c
_08240E9C:
	adds r0, r4, #0
_08240E9E:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08240ea4
FUN_08240ea4: @ 0x08240EA4
	push {r4, r5, r6, lr}
	sub sp, #8
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _08240EE0
	bl FUN_082316bc
	cmp r0, #0
	beq _08240EC4
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _08240EC6
_08240EC4:
	movs r0, #0
_08240EC6:
	adds r6, r0, #0
	bl FUN_082316bc
	cmp r0, #0
	beq _08240EDA
	bl fetch_082316e4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	b _08240EDC
_08240EDA:
	movs r0, #0
_08240EDC:
	adds r5, r0, #0
	b _08240EE4
_08240EE0:
	movs r6, #0
	movs r5, #0
_08240EE4:
	movs r0, #0x72
	movs r1, #0
	bl FUN_0823174c
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	movs r0, #0x66
	movs r1, #1
	bl FUN_0823174c
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r3, #0
	lsls r2, r6, #0x10
	asrs r2, r2, #0x10
	lsls r1, r5, #0x10
	asrs r1, r1, #0x10
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	str r0, [sp]
	str r3, [sp, #4]
	adds r0, r2, #0
	adds r2, r4, #0
	bl FUN_08240bcc
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08240f20
FUN_08240f20: @ 0x08240F20
	push {r4, lr}
	adds r4, r1, #0
	movs r1, #0x10
	movs r3, #0
	adds r0, #0x98
_08240F2A:
	ldr r2, [r0]
	cmp r2, r4
	bne _08240F34
	adds r0, r3, #0
	b _08240F44
_08240F34:
	cmp r2, #0
	bne _08240F3A
	adds r1, r3, #0
_08240F3A:
	adds r0, #4
	adds r3, #1
	cmp r3, #0xf
	ble _08240F2A
	rsbs r0, r1, #0
_08240F44:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08240f4c
FUN_08240f4c: @ 0x08240F4C
	push {r4, r5, lr}
	ldr r0, _08240F64 @ =0x03001700
	ldr r5, [r0]
	cmp r5, #0
	beq _08240F8C
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _08240F8C
	b _08240F84
	.align 2, 0
_08240F64: .4byte 0x03001700
_08240F68:
	bl fetch_082316e4
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08240f20
	cmp r0, #0
	bge _08240F84
	lsls r1, r0, #2
	adds r0, r5, #0
	adds r0, #0x98
	subs r0, r0, r1
	str r4, [r0]
_08240F84:
	bl FUN_082316bc
	cmp r0, #0
	bne _08240F68
_08240F8C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08240f94
FUN_08240f94: @ 0x08240F94
	push {r4, lr}
	ldr r0, _08240FAC @ =0x03001700
	ldr r4, [r0]
	cmp r4, #0
	beq _08240FD4
	movs r0, #0x61
	bl prepare_08231510
	cmp r0, #0
	beq _08240FD4
	b _08240FCC
	.align 2, 0
_08240FAC: .4byte 0x03001700
_08240FB0:
	bl fetch_082316e4
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08240f20
	cmp r0, #0
	blt _08240FCC
	lsls r0, r0, #2
	adds r1, r4, #0
	adds r1, #0x98
	adds r1, r1, r0
	movs r0, #0
	str r0, [r1]
_08240FCC:
	bl FUN_082316bc
	cmp r0, #0
	bne _08240FB0
_08240FD4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08240fdc
FUN_08240fdc: @ 0x08240FDC
	push {lr}
	ldr r0, _08240FFC @ =0x03001700
	ldr r0, [r0]
	cmp r0, #0
	beq _08240FF6
	adds r1, r0, #0
	adds r1, #0x98
	movs r2, #0
	adds r0, #0xd4
_08240FEE:
	str r2, [r0]
	subs r0, #4
	cmp r0, r1
	bge _08240FEE
_08240FF6:
	pop {r0}
	bx r0
	.align 2, 0
_08240FFC: .4byte 0x03001700

	thumb_func_start FUN_08241000
FUN_08241000: @ 0x08241000
	ldr r1, _08241008 @ =0x03001700
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08241008: .4byte 0x03001700

	thumb_func_start FUN_0824100c
FUN_0824100c: @ 0x0824100C
	push {lr}
	adds r2, r0, #0
	cmp r1, #0
	bne _0824101C
	lsls r0, r2, #7
	adds r0, r0, r2
	adds r0, #0x11
	b _08241028
_0824101C:
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #5
	adds r0, r0, r2
	ldr r1, _0824102C @ =0x00000113
	adds r0, r0, r1
_08241028:
	pop {r1}
	bx r1
	.align 2, 0
_0824102C: .4byte 0x00000113

	thumb_func_start FUN_08241030
FUN_08241030: @ 0x08241030
	adds r1, r0, #0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #6
	adds r0, r0, r1
	ldr r1, _08241040 @ =0x00000255
	adds r0, r0, r1
	bx lr
	.align 2, 0
_08241040: .4byte 0x00000255

	thumb_func_start FUN_08241044
FUN_08241044: @ 0x08241044
	ldr r0, _08241050 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0xee
	lsls r1, r1, #2
	adds r0, r0, r1
	bx lr
	.align 2, 0
_08241050: .4byte 0x030046A0

	thumb_func_start FUN_08241054
FUN_08241054: @ 0x08241054
	ldr r0, _08241060 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08241064 @ =0x00000928
	adds r0, r0, r1
	bx lr
	.align 2, 0
_08241060: .4byte 0x030046A0
_08241064: .4byte 0x00000928

	thumb_func_start FUN_08241068
FUN_08241068: @ 0x08241068
	push {lr}
	bl FUN_08241044
	bl FUN_08231d80
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08241078
FUN_08241078: @ 0x08241078
	push {lr}
	bl FUN_08241044
	ldr r1, _08241088 @ =0x030046A0
	ldr r1, [r1]
	subs r0, r0, r1
	pop {r1}
	bx r1
	.align 2, 0
_08241088: .4byte 0x030046A0

	thumb_func_start FUN_0824108c
FUN_0824108c: @ 0x0824108C
	push {r4, lr}
	bl FUN_08241044
	adds r4, r0, #0
	bl FUN_08241054
	subs r0, r0, r4
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_082410a0
FUN_082410a0: @ 0x082410A0
	push {r4, lr}
	bl FUN_08241044
	adds r4, r0, #0
	bl FUN_0824108c
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_08231d5c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_082410bc
FUN_082410bc: @ 0x082410BC
	push {r4, lr}
	movs r0, #0x28
	bl FUN_08243648
	adds r4, r0, #0
	ldr r0, _082410DC @ =0x030047A8
	ldr r1, [r0]
	movs r0, #0
	adds r2, r4, #0
	bl FUN_08243988
	adds r4, #8
	cmp r0, r4
	bne _082410E0
	movs r0, #1
	b _082410E2
	.align 2, 0
_082410DC: .4byte 0x030047A8
_082410E0:
	movs r0, #0
_082410E2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_082410e8
FUN_082410e8: @ 0x082410E8
	push {r4, lr}
	movs r0, #0x28
	bl FUN_08243648
	adds r2, r0, #0
	ldr r4, _08241104 @ =0x030047A8
	ldr r1, [r4]
	movs r0, #0
	bl FUN_082439f0
	cmp r0, #0
	blt _08241108
	movs r0, #1
	b _08241112
	.align 2, 0
_08241104: .4byte 0x030047A8
_08241108:
	ldr r0, [r4]
	movs r1, #0x28
	bl FUN_082309cc
	movs r0, #0
_08241112:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08241118
FUN_08241118: @ 0x08241118
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r2, _08241198 @ =0x030046A0
	ldr r1, [r2]
	ldr r0, _0824119C @ =0x03004594
	ldr r0, [r0]
	str r0, [r1]
	ldr r0, [r2]
	movs r1, #4
	bl FUN_08231d5c
	movs r0, #0x80
	lsls r0, r0, #3
	bl FUN_08243648
	adds r5, r0, #0
	adds r0, r6, #0
	movs r1, #0
	bl FUN_0824100c
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl FUN_08232260
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08243988
	adds r1, r0, #0
	adds r0, r5, #0
	adds r0, #8
	cmp r1, r0
	bne _082411A4
	bl FUN_08241078
	bl FUN_08243648
	adds r5, r0, #0
	adds r0, r6, #0
	movs r1, #1
	bl FUN_0824100c
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl FUN_08232254
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08243988
	adds r1, r0, #0
	adds r0, r5, #0
	adds r0, #8
	cmp r1, r0
	bne _082411A4
	ldr r1, _082411A0 @ =0x030047B4
	movs r0, #1
	str r0, [r1]
	b _082411A6
	.align 2, 0
_08241198: .4byte 0x030046A0
_0824119C: .4byte 0x03004594
_082411A0: .4byte 0x030047B4
_082411A4:
	movs r0, #0
_082411A6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_082411ac
FUN_082411ac: @ 0x082411AC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #3
	bl FUN_08243648
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0824100c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _0824120C @ =0x03004698
	ldr r1, [r1]
	adds r2, r4, #0
	bl FUN_082439f0
	cmp r0, #0
	blt _0824121C
	bl FUN_08241078
	bl FUN_08243648
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0824100c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r5, _08241210 @ =0x030046A0
	ldr r1, [r5]
	adds r2, r4, #0
	bl FUN_082439f0
	cmp r0, #0
	blt _0824121C
	ldr r0, [r5]
	ldr r1, _08241214 @ =0x03004594
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bne _0824121C
	ldr r1, _08241218 @ =0x030047B4
	movs r0, #1
	str r0, [r1]
	b _0824121E
	.align 2, 0
_0824120C: .4byte 0x03004698
_08241210: .4byte 0x030046A0
_08241214: .4byte 0x03004594
_08241218: .4byte 0x030047B4
_0824121C:
	movs r0, #0
_0824121E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08241224
FUN_08241224: @ 0x08241224
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_0824108c
	bl FUN_08243648
	adds r5, r0, #0
	adds r0, r4, #0
	bl FUN_08241030
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl FUN_08241068
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_08243988
	adds r5, #8
	cmp r0, r5
	bne _08241256
	movs r0, #1
	b _08241258
_08241256:
	movs r0, #0
_08241258:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08241260
FUN_08241260: @ 0x08241260
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_0824108c
	bl FUN_08243648
	adds r5, r0, #0
	adds r0, r4, #0
	bl FUN_08241030
	adds r4, r0, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	bl FUN_08241044
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_082439f0
	cmp r0, #0
	blt _08241290
	movs r0, #1
	b _08241292
_08241290:
	movs r0, #0
_08241292:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08241298
FUN_08241298: @ 0x08241298
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, _082412C0 @ =0x00001FF8
	cmp r4, r0
	ble _082412A8
	adds r4, r0, #0
_082412A8:
	movs r0, #4
	rsbs r0, r0, #0
	ands r4, r0
	adds r0, r4, #0
	bl AllocateEntity
	adds r5, r0, #0
	cmp r5, #0
	bne _082412C4
	movs r0, #0
	b _082412EC
	.align 2, 0
_082412C0: .4byte 0x00001FF8
_082412C4:
	asrs r1, r4, #1
	cmp r1, #0
	ble _082412DA
	ldr r0, _082412F4 @ =0x0000ABCD
	adds r2, r0, #0
	adds r0, r5, #0
_082412D0:
	strh r2, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bne _082412D0
_082412DA:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_08243988
	adds r0, r5, #0
	bl FUN_0823092c
	movs r0, #1
_082412EC:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_082412F4: .4byte 0x0000ABCD

	thumb_func_start FUN_082412f8
FUN_082412f8: @ 0x082412F8
	push {r4, lr}
	ldr r0, _0824131C @ =0x030047A8
	ldr r0, [r0]
	ldrb r4, [r0, #8]
	adds r0, r4, #0
	bl FUN_082411ac
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08241320
	adds r0, r4, #0
	bl FUN_08241260
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08241320
	movs r0, #1
	b _08241322
	.align 2, 0
_0824131C: .4byte 0x030047A8
_08241320:
	movs r0, #0
_08241322:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08241328
FUN_08241328: @ 0x08241328
	push {r4, r5, lr}
	ldr r5, _08241354 @ =0x030047A8
	ldr r0, [r5]
	ldrb r1, [r0, #8]
	movs r0, #1
	subs r4, r0, r1
	adds r0, r4, #0
	bl FUN_082411ac
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08241358
	adds r0, r4, #0
	bl FUN_08241260
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08241358
	ldr r0, [r5]
	strb r4, [r0, #8]
	movs r0, #1
	b _0824135A
	.align 2, 0
_08241354: .4byte 0x030047A8
_08241358:
	movs r0, #0
_0824135A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08241360
FUN_08241360: @ 0x08241360
	push {r4, r5, lr}
	ldr r5, _08241394 @ =0x030047A8
	ldr r0, [r5]
	ldrb r1, [r0, #8]
	movs r0, #1
	subs r4, r0, r1
	adds r0, r4, #0
	bl FUN_08241118
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08241398
	adds r0, r4, #0
	bl FUN_08241224
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08241398
	ldr r0, [r5]
	strb r4, [r0, #8]
	bl FUN_082410bc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _0824139A
	.align 2, 0
_08241394: .4byte 0x030047A8
_08241398:
	movs r0, #0
_0824139A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_082413a0
FUN_082413a0: @ 0x082413A0
	push {lr}
	ldr r0, _082413B4 @ =0x030047A8
	ldr r0, [r0]
	ldrb r0, [r0, #8]
	bl FUN_08241260
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_082413B4: .4byte 0x030047A8

	thumb_func_start FUN_082413b8
FUN_082413b8: @ 0x082413B8
	push {r4, r5, lr}
	ldr r0, _082413F4 @ =0x030047A8
	ldr r0, [r0]
	ldrb r4, [r0, #8]
	movs r0, #1
	subs r5, r0, r4
	bl FUN_082410a0
	adds r0, r4, #0
	bl FUN_082411ac
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _082413F8
	bl FUN_08231cec
	adds r0, r5, #0
	bl FUN_08241118
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _082413F8
	adds r0, r5, #0
	bl FUN_08241224
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _082413F8
	movs r0, #1
	b _082413FA
	.align 2, 0
_082413F4: .4byte 0x030047A8
_082413F8:
	movs r0, #0
_082413FA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08241400
FUN_08241400: @ 0x08241400
	push {lr}
	ldr r0, _0824141C @ =0x030047A8
	ldr r2, [r0]
	ldrb r1, [r2, #8]
	movs r0, #1
	subs r0, r0, r1
	strb r0, [r2, #8]
	bl FUN_082410bc
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	pop {r1}
	bx r1
	.align 2, 0
_0824141C: .4byte 0x030047A8

	thumb_func_start FUN_08241420
FUN_08241420: @ 0x08241420
	bx lr
	.align 2, 0

	thumb_func_start FUN_08241424
FUN_08241424: @ 0x08241424
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	adds r5, r6, #4
	ldr r0, _0824143C @ =0x00001004
	adds r0, r0, r6
	mov sb, r0
	ldr r1, _08241440 @ =0x000001FF
	mov r8, r1
	b _08241482
	.align 2, 0
_0824143C: .4byte 0x00001004
_08241440: .4byte 0x000001FF
_08241444:
	adds r0, r5, #0
	bl FUN_0823167c
	movs r4, #0
	adds r7, r5, #0
	adds r7, #8
	ldrh r0, [r5, #4]
	cmp r4, r0
	bge _08241480
	ldr r0, [r6]
	cmp r0, r8
	bhi _08241480
_0824145C:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_082320e4
	mov r1, sb
	adds r1, #4
	mov sb, r1
	subs r1, #4
	stm r1!, {r0}
	ldr r0, [r6]
	adds r0, #1
	str r0, [r6]
	adds r4, #1
	ldrh r1, [r5, #4]
	cmp r4, r1
	bge _08241480
	cmp r0, r8
	bls _0824145C
_08241480:
	adds r5, r7, #0
_08241482:
	ldr r0, [r6]
	cmp r0, r8
	bhi _08241490
	bl FUN_082316bc
	cmp r0, #0
	bne _08241444
_08241490:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082414a0
FUN_082414a0: @ 0x082414A0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	adds r5, r6, #4
	ldr r0, _082414B8 @ =0x00001004
	adds r0, r0, r6
	mov sb, r0
	movs r7, #0
	b _082414F2
	.align 2, 0
_082414B8: .4byte 0x00001004
_082414BC:
	movs r4, #0
	movs r1, #8
	adds r1, r1, r5
	mov r8, r1
	ldrh r1, [r5, #4]
	cmp r4, r1
	bge _082414F0
	cmp r7, r0
	bhs _082414F0
_082414CE:
	mov r0, sb
	adds r0, #4
	mov sb, r0
	subs r0, #4
	ldm r0!, {r2}
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823206c
	adds r7, #1
	adds r4, #1
	ldrh r1, [r5, #4]
	cmp r4, r1
	bge _082414F0
	ldr r0, [r6]
	cmp r7, r0
	blo _082414CE
_082414F0:
	mov r5, r8
_082414F2:
	ldr r0, [r6]
	cmp r7, r0
	blo _082414BC
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08241508
FUN_08241508: @ 0x08241508
	push {r4, r5, lr}
	ldr r5, _08241540 @ =0x00001804
	adds r0, r5, #0
	bl AllocateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08241538
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_082309cc
	adds r0, r4, #0
	bl FUN_08241424
	cmp r0, #0
	blt _08241538
	bl FUN_08231ca8
	adds r0, r4, #0
	bl FUN_082414a0
	cmp r0, #0
	bge _08241544
_08241538:
	movs r0, #1
	rsbs r0, r0, #0
	b _0824154A
	.align 2, 0
_08241540: .4byte 0x00001804
_08241544:
	adds r0, r4, #0
	bl FUN_0823092c
_0824154A:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_08241550
FUN_08241550: @ 0x08241550
	push {lr}
	bl fetch_082316e4
	ldr r1, _0824156C @ =0x030046A0
	ldr r1, [r1]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r1, r1, r2
	str r0, [r1]
	ldr r1, _08241570 @ =0x03004860
	movs r0, #1
	str r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_0824156C: .4byte 0x030046A0
_08241570: .4byte 0x03004860

	thumb_func_start FUN_08241574
FUN_08241574: @ 0x08241574
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08241584 @ =0x03001704
	ldr r0, [r0]
	cmp r0, #0
	bne _0824158C
	b _082415B0
	.align 2, 0
_08241584: .4byte 0x03001704
_08241588:
	ldr r0, [r4]
	b _082415B4
_0824158C:
	movs r5, #0
	adds r4, r0, #0
	adds r4, #0x18
_08241592:
	ldr r0, [r4]
	cmp r0, #0
	ble _082415B0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r1, r6, #0
	bl FUN_08234d50
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08241588
	adds r4, #4
	adds r5, #1
	cmp r5, #0xf
	ble _08241592
_082415B0:
	movs r0, #1
	rsbs r0, r0, #0
_082415B4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082415bc
FUN_082415bc: @ 0x082415BC
	movs r0, #0
	bx lr

	thumb_func_start FUN_082415c0
FUN_082415c0: @ 0x082415C0
	ldr r0, _082415D0 @ =0x03001704
	movs r1, #0
	str r1, [r0]
	ldr r0, _082415D4 @ =0x03004860
	str r1, [r0]
	movs r0, #0
	bx lr
	.align 2, 0
_082415D0: .4byte 0x03001704
_082415D4: .4byte 0x03004860

	thumb_func_start FUN_082415d8
FUN_082415d8: @ 0x082415D8
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x6d
	bl prepare_08231510
	cmp r0, #0
	beq _082415FA
	adds r4, r5, #0
	adds r4, #0x18
	b _082415F2
_082415EC:
	bl fetch_082316e4
	stm r4!, {r0}
_082415F2:
	bl FUN_082316bc
	cmp r0, #0
	bne _082415EC
_082415FA:
	ldr r0, _08241608 @ =0x03001704
	str r5, [r0]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08241608: .4byte 0x03001704

	thumb_func_start FUN_0824160c
FUN_0824160c: @ 0x0824160C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r0, #4
	movs r1, #0x58
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08241648
	ldr r1, _08241640 @ =FUN_082415bc
	ldr r2, _08241644 @ =FUN_082415c0
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_082415d8
	cmp r0, #0
	bge _08241648
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0824164A
	.align 2, 0
_08241640: .4byte FUN_082415bc
_08241644: .4byte FUN_082415c0
_08241648:
	adds r0, r4, #0
_0824164A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_08241650
FUN_08241650: @ 0x08241650
	ldr r0, _08241678 @ =0x03001708
	movs r1, #0
	str r1, [r0]
	ldr r2, _0824167C @ =0x030046A0
	ldr r0, [r2]
	movs r3, #0x94
	lsls r3, r3, #4
	adds r0, r0, r3
	strh r1, [r0]
	ldr r0, [r2]
	ldr r2, _08241680 @ =0x00000942
	adds r0, r0, r2
	strh r1, [r0]
	ldr r0, _08241684 @ =0x03004870
	strh r1, [r0]
	ldr r0, _08241688 @ =0x03004874
	strh r1, [r0]
	ldr r0, _0824168C @ =0x0300486C
	strh r1, [r0]
	bx lr
	.align 2, 0
_08241678: .4byte 0x03001708
_0824167C: .4byte 0x030046A0
_08241680: .4byte 0x00000942
_08241684: .4byte 0x03004870
_08241688: .4byte 0x03004874
_0824168C: .4byte 0x0300486C

	thumb_func_start FUN_08241690
FUN_08241690: @ 0x08241690
	push {lr}
	ldr r0, _082416AC @ =0x03001708
	ldr r1, [r0]
	cmp r1, #0
	beq _082416B4
	ldr r0, _082416B0 @ =0x0300486C
	ldrh r0, [r0]
	cmp r0, #0
	bne _082416B4
	ldrb r0, [r1, #0x19]
	cmp r0, #2
	bne _082416B4
	movs r0, #1
	b _082416B6
	.align 2, 0
_082416AC: .4byte 0x03001708
_082416B0: .4byte 0x0300486C
_082416B4:
	movs r0, #0
_082416B6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082416bc
FUN_082416bc: @ 0x082416BC
	ldr r1, _082416C4 @ =0x03004864
	movs r0, #1
	strh r0, [r1]
	bx lr
	.align 2, 0
_082416C4: .4byte 0x03004864

	thumb_func_start FUN_082416c8
FUN_082416c8: @ 0x082416C8
	ldr r1, _082416D0 @ =0x03004864
	movs r0, #0
	strh r0, [r1]
	bx lr
	.align 2, 0
_082416D0: .4byte 0x03004864

	thumb_func_start FUN_082416d4
FUN_082416d4: @ 0x082416D4
	push {lr}
	ldr r0, _082416F4 @ =0x03001708
	ldr r0, [r0]
	ldrb r0, [r0, #0x19]
	cmp r0, #2
	bne _082416FC
	bl FUN_082477e0
	cmp r0, #0
	blt _082416FC
	subs r0, #2
	ldr r1, _082416F8 @ =0x030047A8
	ldr r1, [r1]
	str r0, [r1, #4]
	movs r0, #1
	b _082416FE
	.align 2, 0
_082416F4: .4byte 0x03001708
_082416F8: .4byte 0x030047A8
_082416FC:
	movs r0, #0
_082416FE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08241704
FUN_08241704: @ 0x08241704
	push {lr}
	ldr r0, _08241724 @ =0x03001708
	ldr r0, [r0]
	cmp r0, #0
	beq _0824171E
	ldrb r0, [r0, #0x19]
	cmp r0, #0
	beq _08241718
	bl FUN_082477b4
_08241718:
	ldr r1, _08241728 @ =0x0300486C
	movs r0, #1
	strh r0, [r1]
_0824171E:
	pop {r0}
	bx r0
	.align 2, 0
_08241724: .4byte 0x03001708
_08241728: .4byte 0x0300486C

	thumb_func_start FUN_0824172c
FUN_0824172c: @ 0x0824172C
	push {lr}
	ldr r3, _08241754 @ =0x03001708
	ldr r2, [r3]
	cmp r2, #0
	beq _08241750
	ldrb r0, [r2, #0x19]
	cmp r0, #0
	beq _0824174A
	movs r0, #0
	movs r1, #1
	strb r1, [r2, #0x19]
	ldr r1, [r3]
	strh r0, [r1, #0x20]
	bl FUN_08247774
_0824174A:
	ldr r1, _08241758 @ =0x0300486C
	movs r0, #0
	strh r0, [r1]
_08241750:
	pop {r0}
	bx r0
	.align 2, 0
_08241754: .4byte 0x03001708
_08241758: .4byte 0x0300486C

	thumb_func_start FUN_0824175c
FUN_0824175c: @ 0x0824175C
	ldr r0, _0824176C @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _08241770 @ =0x00000942
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	bx lr
	.align 2, 0
_0824176C: .4byte 0x030046A0
_08241770: .4byte 0x00000942

	thumb_func_start FUN_08241774
FUN_08241774: @ 0x08241774
	push {lr}
	cmp r0, #0
	bne _0824177E
	movs r0, #0
	b _082417C8
_0824177E:
	cmp r0, #5
	bgt _08241786
	movs r0, #1
	b _082417C8
_08241786:
	cmp r0, #0xc
	bgt _0824178E
	movs r0, #2
	b _082417C8
_0824178E:
	cmp r0, #0x16
	bgt _08241796
	movs r0, #3
	b _082417C8
_08241796:
	cmp r0, #0x22
	bgt _0824179E
	movs r0, #4
	b _082417C8
_0824179E:
	cmp r0, #0x31
	bgt _082417A6
	movs r0, #5
	b _082417C8
_082417A6:
	cmp r0, #0x42
	bgt _082417AE
	movs r0, #6
	b _082417C8
_082417AE:
	cmp r0, #0x56
	bgt _082417B6
	movs r0, #7
	b _082417C8
_082417B6:
	cmp r0, #0x6d
	bgt _082417BE
	movs r0, #8
	b _082417C8
_082417BE:
	cmp r0, #0x8b
	ble _082417C6
	movs r0, #0xa
	b _082417C8
_082417C6:
	movs r0, #9
_082417C8:
	pop {r1}
	bx r1

	thumb_func_start FUN_082417cc
FUN_082417cc: @ 0x082417CC
	ldr r1, _082417D8 @ =0x08DBD7A4
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_082417D8: .4byte 0x08DBD7A4

	thumb_func_start FUN_082417dc
FUN_082417dc: @ 0x082417DC
	ldr r1, _082417E8 @ =0x08DBD7BA
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_082417E8: .4byte 0x08DBD7BA

	thumb_func_start FUN_082417ec
FUN_082417ec: @ 0x082417EC
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08241850 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _082418B6
	ldr r0, _08241854 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0824182C
	movs r1, #0x80
	lsls r1, r1, #6
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0824182C
	adds r0, r4, #0
	bl FUN_08241774
	lsls r0, r0, #1
	cmp r0, #0xa
	ble _08241826
	movs r0, #0xa
_08241826:
	bl FUN_082417cc
	adds r4, r0, #0
_0824182C:
	ldr r0, _08241858 @ =0x030046A0
	ldr r1, [r0]
	movs r2, #0xac
	lsls r2, r2, #2
	adds r0, r1, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	beq _0824185C
	adds r0, r4, #0
	bl FUN_08241774
	cmp r0, #1
	bgt _0824187A
	movs r0, #2
	bl FUN_082417dc
	b _08241878
	.align 2, 0
_08241850: .4byte 0x030047A4
_08241854: .4byte 0x03002BE0
_08241858: .4byte 0x030046A0
_0824185C:
	ldr r2, _082418A0 @ =0x000002B2
	adds r0, r1, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _0824187A
	adds r0, r4, #0
	bl FUN_08241774
	cmp r0, #2
	ble _0824187A
	movs r0, #2
	bl FUN_082417cc
_08241878:
	adds r4, r0, #0
_0824187A:
	ldr r0, _082418A4 @ =0x03002B80
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #1
	bne _08241886
	movs r1, #1
_08241886:
	cmp r1, #0
	beq _082418A8
	adds r0, r4, #0
	bl FUN_08241774
	adds r0, #4
	cmp r0, #0xa
	ble _08241898
	movs r0, #0xa
_08241898:
	bl FUN_082417cc
	adds r4, r0, #0
	b _082418B6
	.align 2, 0
_082418A0: .4byte 0x000002B2
_082418A4: .4byte 0x03002B80
_082418A8:
	movs r1, #0
	cmp r0, #2
	bne _082418B0
	movs r1, #1
_082418B0:
	cmp r1, #0
	beq _082418B6
	movs r4, #0
_082418B6:
	adds r0, r4, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_082418c0
FUN_082418c0: @ 0x082418C0
	push {lr}
	bl FUN_082477e0
	adds r1, r0, #0
	cmp r1, #0
	blt _082418D6
	ldr r0, _082418DC @ =0x030047A8
	ldr r0, [r0]
	ldr r0, [r0, #4]
	cmp r1, r0
	ble _082418E0
_082418D6:
	movs r0, #0
	b _082418EC
	.align 2, 0
_082418DC: .4byte 0x030047A8
_082418E0:
	subs r1, r0, r1
	cmp r1, #0x8b
	bgt _082418EA
	adds r0, r1, #0
	b _082418EC
_082418EA:
	movs r0, #0x8c
_082418EC:
	pop {r1}
	bx r1

