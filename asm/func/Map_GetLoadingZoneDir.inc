	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov ip, r0
	ldrh r1, [r0, #4]
	subs r1, #0x10
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080A654C @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r0, ip
	movs r3, #6
	ldrsh r1, [r0, r3]
	movs r4, #2
	ldrsh r0, [r0, r4]
	adds r1, r1, r0
	lsls r1, r1, #0xf
	lsrs r1, r1, #0x10
	mov r4, sp
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r3, sp, #8
	ldrh r0, [r3]
	adds r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	mov sb, r3
	cmp r2, #0
	blt _080A6546
	cmp r1, #0
	blt _080A6546
	ldr r0, _080A6550 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A6546
	ldr r0, _080A6554 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A6558
_080A6546:
	movs r4, #0
	b _080A6566
	.align 2, 0
_080A654C: .4byte 0xFFFF0000
_080A6550: .4byte 0x030046A8
_080A6554: .4byte 0x030046AC
_080A6558:
	ldr r0, _080A6594 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A6566:
	add r0, sp, #8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sb
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A658E
	cmp r1, #0
	blt _080A658E
	ldr r0, _080A6598 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A658E
	ldr r0, _080A659C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A65A0
_080A658E:
	movs r3, #0
	b _080A65AE
	.align 2, 0
_080A6594: .4byte 0x030046A4
_080A6598: .4byte 0x030046A8
_080A659C: .4byte 0x030046AC
_080A65A0:
	ldr r0, _080A65C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r2
_080A65AE:
	cmp r4, r3
	beq _080A6650
	ldr r1, _080A65C4 @ =0x030046A4
	ldr r0, [r1]
	ldr r2, [r0, #4]
	mov r8, r1
	cmp r2, #0
	bne _080A65C8
	movs r2, #0
	b _080A65CE
	.align 2, 0
_080A65C4: .4byte 0x030046A4
_080A65C8:
	lsls r0, r4, #2
	adds r0, #0xc
	adds r2, r2, r0
_080A65CE:
	mov r4, r8
	ldr r0, [r4]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A65DC
	movs r7, #0
	b _080A65E2
_080A65DC:
	lsls r0, r3, #2
	adds r0, #0xc
	adds r7, r1, r0
_080A65E2:
	ldrb r0, [r2]
	movs r4, #0xf
	lsrs r2, r0, #4
	adds r5, r0, #0
	cmp r2, #1
	beq _080A6654
	cmp r2, #1
	blo _080A65F8
	cmp r2, #2
	beq _080A662A
	b _080A6654
_080A65F8:
	ldrb r1, [r7]
	lsrs r0, r1, #4
	ands r0, r4
	adds r2, r1, #0
	cmp r0, #0
	bne _080A661A
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r2
	cmp r1, r0
	bne _080A661A
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A6650
_080A661A:
	lsrs r0, r2, #4
	cmp r0, #2
	bne _080A6654
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r2
	b _080A6642
_080A662A:
	ldrb r2, [r7]
	lsrs r0, r2, #4
	ands r0, r4
	cmp r0, #0
	beq _080A6638
	cmp r0, #2
	bne _080A6654
_080A6638:
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r2
	adds r0, #1
_080A6642:
	cmp r1, r0
	bne _080A6654
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080A6654
_080A6650:
	movs r0, #0
	b _080A6A64
_080A6654:
	mov r1, ip
	movs r2, #4
	ldrsh r0, [r1, r2]
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	asrs r0, r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r4, ip
	ldrh r0, [r4, #6]
	subs r0, #0x10
	mov r2, sp
	strh r0, [r2, #4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r1, sb
	ldrh r0, [r1, #4]
	adds r0, #0x20
	strh r0, [r1, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _080A66A6
	cmp r1, #0
	blt _080A66A6
	ldr r0, _080A66AC @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _080A66A6
	ldr r0, _080A66B0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A66B4
_080A66A6:
	movs r4, #0
	b _080A66C2
	.align 2, 0
_080A66AC: .4byte 0x030046A8
_080A66B0: .4byte 0x030046AC
_080A66B4:
	mov r2, r8
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_080A66C2:
	add r0, sp, #8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r3, sb
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A66EA
	cmp r1, #0
	blt _080A66EA
	ldr r0, _080A66F0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A66EA
	ldr r0, _080A66F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A66F8
_080A66EA:
	movs r3, #0
	b _080A6706
	.align 2, 0
_080A66F0: .4byte 0x030046A8
_080A66F4: .4byte 0x030046AC
_080A66F8:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r2
_080A6706:
	cmp r4, r3
	beq _080A67A0
	mov r1, r8
	ldr r0, [r1]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A6718
	movs r2, #0
	b _080A671E
_080A6718:
	lsls r0, r4, #2
	adds r0, #0xc
	adds r2, r1, r0
_080A671E:
	mov r4, r8
	ldr r0, [r4]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A672C
	movs r7, #0
	b _080A6732
_080A672C:
	lsls r0, r3, #2
	adds r0, #0xc
	adds r7, r1, r0
_080A6732:
	ldrb r0, [r2]
	movs r3, #0xf
	lsrs r2, r0, #4
	adds r5, r0, #0
	cmp r2, #1
	beq _080A677C
	cmp r2, #1
	bhs _080A67A4
	ldrb r1, [r7]
	lsrs r0, r1, #4
	ands r0, r3
	adds r2, r1, #0
	cmp r0, #0
	bne _080A6764
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r2
	cmp r1, r0
	bne _080A6764
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A67A0
_080A6764:
	lsrs r4, r2, #4
	cmp r4, #1
	bne _080A67A4
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r2
	cmp r1, r0
	bne _080A67A4
	ldrh r0, [r7, #2]
	ands r0, r4
	b _080A679C
_080A677C:
	ldrb r4, [r7]
	lsrs r0, r4, #4
	ands r0, r3
	cmp r0, #0
	beq _080A678A
	cmp r0, #1
	bne _080A67A4
_080A678A:
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r4
	adds r0, #1
	cmp r1, r0
	bne _080A67A4
	ldrh r0, [r7, #2]
	ands r0, r2
_080A679C:
	cmp r0, #0
	bne _080A67A4
_080A67A0:
	movs r0, #1
	b _080A6A64
_080A67A4:
	mov r1, ip
	ldrh r0, [r1]
	adds r0, #0x10
	mov r1, sp
	strh r0, [r1]
	mov r2, ip
	movs r3, #6
	ldrsh r0, [r2, r3]
	movs r4, #2
	ldrsh r1, [r2, r4]
	adds r0, r0, r1
	asrs r0, r0, #1
	mov r2, sp
	strh r0, [r2, #4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r1, sb
	ldrh r0, [r1]
	subs r0, #0x20
	add r1, sp, #8
	strh r0, [r1]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _080A67F8
	cmp r1, #0
	blt _080A67F8
	ldr r0, _080A67FC @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _080A67F8
	ldr r0, _080A6800 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A6804
_080A67F8:
	movs r4, #0
	b _080A6812
	.align 2, 0
_080A67FC: .4byte 0x030046A8
_080A6800: .4byte 0x030046AC
_080A6804:
	mov r2, r8
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_080A6812:
	add r0, sp, #8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r3, sb
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A683A
	cmp r1, #0
	blt _080A683A
	ldr r0, _080A6840 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A683A
	ldr r0, _080A6844 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A6848
_080A683A:
	movs r3, #0
	b _080A6856
	.align 2, 0
_080A6840: .4byte 0x030046A8
_080A6844: .4byte 0x030046AC
_080A6848:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r2
_080A6856:
	cmp r4, r3
	beq _080A68FE
	mov r1, r8
	ldr r0, [r1]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A6868
	movs r2, #0
	b _080A686E
_080A6868:
	lsls r0, r4, #2
	adds r0, #0xc
	adds r2, r1, r0
_080A686E:
	mov r4, r8
	ldr r0, [r4]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A687C
	movs r7, #0
	b _080A6882
_080A687C:
	lsls r0, r3, #2
	adds r0, #0xc
	adds r7, r1, r0
_080A6882:
	ldrb r0, [r2]
	movs r6, #0xf
	lsrs r2, r0, #4
	adds r5, r0, #0
	cmp r2, #1
	beq _080A6902
	cmp r2, #1
	blo _080A6898
	cmp r2, #2
	beq _080A68CC
	b _080A6902
_080A6898:
	ldrb r1, [r7]
	lsrs r0, r1, #4
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	bne _080A68BA
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r2
	cmp r1, r0
	bne _080A68BA
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A68FE
_080A68BA:
	lsrs r0, r2, #4
	cmp r0, #2
	bne _080A6902
	movs r1, #0xf
	adds r0, r1, #0
	ands r0, r5
	adds r0, #1
	ands r1, r2
	b _080A68F0
_080A68CC:
	ldrb r4, [r7]
	lsrs r2, r4, #4
	ands r2, r6
	cmp r2, #0
	bne _080A68E2
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r5
	ands r0, r4
	cmp r1, r0
	beq _080A68F4
_080A68E2:
	cmp r2, #2
	bne _080A6902
	movs r1, #0xf
	adds r0, r1, #0
	ands r0, r5
	adds r0, #1
	ands r1, r4
_080A68F0:
	cmp r0, r1
	bne _080A6902
_080A68F4:
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080A6902
_080A68FE:
	movs r0, #2
	b _080A6A64
_080A6902:
	mov r1, ip
	movs r2, #4
	ldrsh r0, [r1, r2]
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r0, r0, r1
	asrs r0, r0, #1
	mov r1, sp
	strh r0, [r1]
	mov r4, ip
	ldrh r0, [r4, #2]
	adds r0, #0x10
	mov r2, sp
	strh r0, [r2, #4]
	ldr r0, [sp]
	ldr r1, [sp, #4]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	mov r1, sb
	ldrh r0, [r1, #4]
	subs r0, #0x20
	strh r0, [r1, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r4, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r4, #0
	blt _080A6954
	cmp r1, #0
	blt _080A6954
	ldr r0, _080A6958 @ =0x030046A8
	ldr r0, [r0]
	cmp r4, r0
	bhs _080A6954
	ldr r0, _080A695C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A6960
_080A6954:
	movs r4, #0
	b _080A696E
	.align 2, 0
_080A6958: .4byte 0x030046A8
_080A695C: .4byte 0x030046AC
_080A6960:
	mov r2, r8
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r4
_080A696E:
	add r0, sp, #8
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	mov r1, sb
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080A6996
	cmp r1, #0
	blt _080A6996
	ldr r0, _080A699C @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080A6996
	ldr r0, _080A69A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A69A4
_080A6996:
	movs r3, #0
	b _080A69B2
	.align 2, 0
_080A699C: .4byte 0x030046A8
_080A69A0: .4byte 0x030046AC
_080A69A4:
	mov r2, r8
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r3, r0, r3
_080A69B2:
	cmp r4, r3
	beq _080A6A5C
	mov r1, r8
	ldr r0, [r1]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A69C4
	movs r2, #0
	b _080A69CA
_080A69C4:
	lsls r0, r4, #2
	adds r0, #0xc
	adds r2, r1, r0
_080A69CA:
	mov r4, r8
	ldr r0, [r4]
	ldr r1, [r0, #4]
	cmp r1, #0
	bne _080A69D8
	movs r7, #0
	b _080A69DE
_080A69D8:
	lsls r0, r3, #2
	adds r0, #0xc
	adds r7, r1, r0
_080A69DE:
	ldrb r3, [r2]
	movs r6, #0xf
	lsrs r0, r3, #4
	adds r5, r3, #0
	cmp r0, #1
	beq _080A6A2A
	cmp r0, #1
	bhs _080A6A60
	ldrb r1, [r7]
	lsrs r0, r1, #4
	ands r0, r6
	adds r2, r1, #0
	cmp r0, #0
	bne _080A6A10
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r3
	ands r0, r2
	cmp r1, r0
	bne _080A6A10
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080A6A5C
_080A6A10:
	lsrs r4, r2, #4
	cmp r4, #1
	bne _080A6A60
	movs r1, #0xf
	adds r0, r1, #0
	ands r0, r5
	adds r0, #1
	ands r1, r2
	cmp r0, r1
	bne _080A6A60
	ldrh r0, [r7, #2]
	ands r0, r4
	b _080A6A58
_080A6A2A:
	ldrb r4, [r7]
	lsrs r2, r4, #4
	ands r2, r6
	cmp r2, #0
	bne _080A6A40
	movs r0, #0xf
	adds r1, r0, #0
	ands r1, r3
	ands r0, r4
	cmp r1, r0
	beq _080A6A52
_080A6A40:
	cmp r2, #1
	bne _080A6A60
	movs r1, #0xf
	adds r0, r1, #0
	ands r0, r3
	adds r0, #1
	ands r1, r4
	cmp r0, r1
	bne _080A6A60
_080A6A52:
	ldrh r0, [r7, #2]
	movs r1, #1
	ands r0, r1
_080A6A58:
	cmp r0, #0
	bne _080A6A60
_080A6A5C:
	movs r0, #3
	b _080A6A64
_080A6A60:
	movs r0, #1
	rsbs r0, r0, #0
_080A6A64:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
